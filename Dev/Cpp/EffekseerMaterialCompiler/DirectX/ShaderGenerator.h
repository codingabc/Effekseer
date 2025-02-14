#pragma once

#include "../../Effekseer/Effekseer/Material/Effekseer.MaterialCompiler.h"
#include <string>
#include <vector>

#include "../HLSL/HLSL.h"

#ifdef _WIN32
#undef min
#endif

namespace Effekseer
{
namespace DirectX
{

struct ShaderData
{
	std::string CodeVS;
	std::string CodePS;
};

enum class ShaderGeneratorTarget
{
	DirectX9,
	DirectX11,
	DirectX12,
};

class ShaderGenerator
{
protected:
	std::string common_define_;
	std::string common_functions_;
	std::string common_vs_define_;
	std::string sprite_vs_pre_;
	std::string sprite_vs_pre_simple_;
	std::string model_vs_pre_;
	std::string sprite_vs_suf1_;
	std::string sprite_vs_suf1_simple_;
	std::string model_vs_suf1_;
	std::string sprite_vs_suf2_;
	std::string model_vs_suf2_;
	std::string ps_pre_;
	std::string ps_suf1_;
	std::string ps_suf2_lit_;
	std::string ps_suf2_unlit_;
	std::string ps_suf2_refraction_;
	ShaderGeneratorTarget target_;

	std::string Replace(std::string target, std::string from_, std::string to_)
	{
		std::string::size_type Pos(target.find(from_));

		while (Pos != std::string::npos)
		{
			target.replace(Pos, from_.length(), to_);
			Pos = target.find(from_, Pos + to_.length());
		}

		return target;
	}

	std::string GetType(int32_t i)
	{
		if (i == 1)
			return "float";
		if (i == 2)
			return "float2";
		if (i == 3)
			return "float3";
		if (i == 4)
			return "float4";
		if (i == 16)
			return "float4x4";
		assert(0);
		return "";
	}

	std::string GetElement(int32_t i)
	{
		if (i == 1)
			return ".x";
		if (i == 2)
			return ".xy";
		if (i == 3)
			return ".xyz";
		if (i == 4)
			return ".xyzw";
		assert(0);
		return "";
	}

	void ExportUniform(std::ostringstream& maincode, int32_t type, const char* name, int32_t registerId)
	{
		maincode << GetType(type) << " " << name << " : register(c" << registerId << ");" << std::endl;
	}

	void ExportTexture(std::ostringstream& maincode, const char* name, int32_t registerId)
	{
		maincode << "Texture2D " << name << "_texture : register(t" << registerId << ");" << std::endl;

		if (target_ == ShaderGeneratorTarget::DirectX9)
		{
			maincode << "sampler2D " << name << "_sampler : register(s" << registerId << ");" << std::endl;
		}
		else
		{
			maincode << "SamplerState " << name << "_sampler : register(s" << registerId << ");" << std::endl;
		}
	}

	int32_t ExportHeader(std::ostringstream& maincode, MaterialFile* materialFile, int stage, bool isSprite, int instanceCount)
	{
		auto cind = 0;

		maincode << common_define_;

		// gradient
		bool hasGradient = false;
		bool hasNoise = false;

		for (const auto& type : materialFile->RequiredMethods)
		{
			if (type == MaterialFile::RequiredPredefinedMethodType::Gradient)
			{
				hasGradient = true;
			}
			else if (type == MaterialFile::RequiredPredefinedMethodType::Noise)
			{
				hasNoise = true;
			}
		}

		if (hasGradient)
		{
			maincode << HLSL::material_gradient;
		}

		if (hasNoise)
		{
			maincode << HLSL::material_noise;
		}

		for (const auto& gradient : materialFile->FixedGradients)
		{
			maincode << HLSL::GetFixedGradient(gradient.Name.c_str(), gradient.Data);
		}

		if (stage == 0)
		{
			if (isSprite)
			{
				if (materialFile->GetIsSimpleVertex())
				{
					maincode << sprite_vs_pre_simple_;
				}
				else
				{
					maincode << sprite_vs_pre_;
				}
				cind = 11;
			}
			else
			{
				maincode << model_vs_pre_;
				cind = 7 + instanceCount * 6;
			}
		}
		else
		{
			maincode << ps_pre_;
			cind = 2;
		}

		return cind;
	}

	void ExportMain(std::ostringstream& maincode,
					MaterialFile* materialFile,
					int stage,
					bool isSprite,
					MaterialShaderType shaderType,
					const std::string& baseCode)
	{
		if (stage == 0)
		{
			if (isSprite)
			{
				if (materialFile->GetIsSimpleVertex())
				{
					maincode << sprite_vs_suf1_simple_;
				}
				else
				{
					maincode << sprite_vs_suf1_;
				}
			}
			else
			{
				maincode << model_vs_suf1_;
			}

			if (materialFile->GetCustomData1Count() > 0)
			{
				if (isSprite)
				{
					maincode << GetType(materialFile->GetCustomData1Count()) + " customData1 = Input.CustomData1;\n";
				}
				else
				{
					maincode << GetType(materialFile->GetCustomData1Count()) + " customData1 = customData1_[Input.Index];\n";
				}
				maincode << "Output.CustomData1 = customData1" + GetElement(materialFile->GetCustomData1Count()) + ";\n";
			}

			if (materialFile->GetCustomData2Count() > 0)
			{
				if (isSprite)
				{
					maincode << GetType(materialFile->GetCustomData2Count()) + " customData2 = Input.CustomData2;\n";
				}
				else
				{
					maincode << GetType(materialFile->GetCustomData2Count()) + " customData2 = customData2_[Input.Index];\n";
				}
				maincode << "Output.CustomData2 = customData2" + GetElement(materialFile->GetCustomData2Count()) + ";\n";
			}
		}
		else
		{
			maincode << ps_suf1_;

			if (materialFile->GetCustomData1Count() > 0)
			{
				maincode << GetType(materialFile->GetCustomData1Count()) + " customData1 = Input.CustomData1;\n";
			}

			if (materialFile->GetCustomData2Count() > 0)
			{
				maincode << GetType(materialFile->GetCustomData2Count()) + " customData2 = Input.CustomData2;\n";
			}
		}

		maincode << baseCode;

		if (stage == 0)
		{
			if (isSprite)
			{
				maincode << sprite_vs_suf2_;
			}
			else
			{
				maincode << model_vs_suf2_;
			}
		}
		else
		{
			if (shaderType == MaterialShaderType::Refraction || shaderType == MaterialShaderType::RefractionModel)
			{
				maincode << ps_suf2_refraction_;
			}
			else
			{
				if (materialFile->GetShadingModel() == Effekseer::ShadingModelType::Lit)
				{
					maincode << ps_suf2_lit_;
				}
				else if (materialFile->GetShadingModel() == Effekseer::ShadingModelType::Unlit)
				{
					maincode << ps_suf2_unlit_;
				}
				else
				{
					assert(0);
				}
			}
		}
	}

public:
	ShaderGenerator(const std::string& common_define,
					const std::string& common_functions,
					const std::string& common_vs_define,
					const std::string& sprite_vs_pre,
					const std::string& sprite_vs_pre_simple,
					const std::string& model_vs_pre,
					const std::string& sprite_vs_suf1,
					const std::string& sprite_vs_suf1_simple,
					const std::string& model_vs_suf1,
					const std::string& sprite_vs_suf2,
					const std::string& model_vs_suf2,
					const std::string& ps_pre,
					const std::string& ps_suf1,
					const std::string& ps_suf2_lit,
					const std::string& ps_suf2_unlit,
					const std::string& ps_suf2_refraction,
					ShaderGeneratorTarget target)
		: common_define_(common_define)
		, common_functions_(common_functions)
		, common_vs_define_(common_vs_define)
		, sprite_vs_pre_(sprite_vs_pre)
		, sprite_vs_pre_simple_(sprite_vs_pre_simple)
		, model_vs_pre_(model_vs_pre)
		, sprite_vs_suf1_(sprite_vs_suf1)
		, sprite_vs_suf1_simple_(sprite_vs_suf1_simple)
		, model_vs_suf1_(model_vs_suf1)
		, sprite_vs_suf2_(sprite_vs_suf2)
		, model_vs_suf2_(model_vs_suf2)
		, ps_pre_(ps_pre)
		, ps_suf1_(ps_suf1)
		, ps_suf2_lit_(ps_suf2_lit)
		, ps_suf2_unlit_(ps_suf2_unlit)
		, ps_suf2_refraction_(ps_suf2_refraction)
		, target_(target)
	{
	}

	ShaderData GenerateShader(MaterialFile* materialFile,
							  MaterialShaderType shaderType,
							  int32_t maximumUniformCount,
							  int32_t maximumTextureCount,
							  int32_t pixelShaderTextureSlotOffset,
							  int32_t instanceCount)
	{
		ShaderData shaderData;

		bool isSprite = shaderType == MaterialShaderType::Standard || shaderType == MaterialShaderType::Refraction;
		bool isRefrection = materialFile->GetHasRefraction() &&
							(shaderType == MaterialShaderType::Refraction || shaderType == MaterialShaderType::RefractionModel);

		for (int stage = 0; stage < 2; stage++)
		{
			std::ostringstream maincode;

			auto cind = ExportHeader(maincode, materialFile, stage, isSprite, instanceCount);

			if (stage == 1)
			{
				ExportUniform(maincode, 4, "mUVInversedBack", 0);
				ExportUniform(maincode, 4, "predefined_uniform", 1);
				ExportUniform(maincode, 4, "cameraPosition", cind + 0);
				ExportUniform(maincode, 4, "reconstructionParam1", cind + 1);
				ExportUniform(maincode, 4, "reconstructionParam2", cind + 2);
				cind += 3;
			}

			if (stage == 1)
			{
				ExportUniform(maincode, 4, "lightDirection", cind);
				cind++;
				ExportUniform(maincode, 4, "lightColor", cind);
				cind++;
				ExportUniform(maincode, 4, "lightAmbientColor", cind);
				cind++;
			}

			if (materialFile->GetShadingModel() == ::Effekseer::ShadingModelType::Lit && stage == 1)
			{
				maincode << "#define _MATERIAL_LIT_ 1" << std::endl;
			}
			else if (materialFile->GetShadingModel() == ::Effekseer::ShadingModelType::Unlit)
			{
			}

			if (isRefrection && stage == 1)
			{
				ExportUniform(maincode, 16, "cameraMat", cind);
				cind += 4;
			}

			if (!isSprite && stage == 0)
			{
				if (materialFile->GetCustomData1Count() > 0)
				{
					maincode << "float4 customData1_[" << instanceCount << "]"
							 << " : register(c" << cind << ");" << std::endl;
					cind += instanceCount;
				}
				if (materialFile->GetCustomData2Count() > 0)
				{
					maincode << "float4 customData2_[" << instanceCount << "]"
							 << " : register(c" << cind << ");" << std::endl;
					cind += instanceCount;
				}
			}

			int32_t actualUniformCount = std::min(maximumUniformCount, materialFile->GetUniformCount());

			for (int32_t i = 0; i < actualUniformCount; i++)
			{
				ExportUniform(maincode, 4, materialFile->GetUniformName(i), cind);
				cind++;
			}

			for (size_t i = 0; i < materialFile->Gradients.size(); i++)
			{
				// TODO : remove a magic number
				for (size_t j = 0; j < 13; j++)
				{
					ExportUniform(maincode, 4, (materialFile->Gradients[i].Name + "_" + std::to_string(j)).c_str(), cind);
				}
				cind++;
			}

			// finish constant buffer
			maincode << "};" << std::endl;

			for (int32_t i = actualUniformCount; i < materialFile->GetUniformCount(); i++)
			{
				maincode << "const " << GetType(4) << " " << materialFile->GetUniformName(i) << " = float4(0,0,0,0);" << std::endl;
			}

			int32_t textureSlotOffset = 0;

			if (stage == 1)
			{
				textureSlotOffset = pixelShaderTextureSlotOffset;
			}

			int32_t actualTextureCount = std::min(maximumTextureCount, materialFile->GetTextureCount());

			for (int32_t i = 0; i < actualTextureCount; i++)
			{
				ExportTexture(maincode, materialFile->GetTextureName(i), i + textureSlotOffset);
			}

			textureSlotOffset += actualTextureCount;

			// background
			ExportTexture(maincode, "efk_background", 0 + textureSlotOffset);

			// depth
			ExportTexture(maincode, "efk_depth", 1 + textureSlotOffset);

			if (std::find(materialFile->RequiredMethods.begin(), materialFile->RequiredMethods.end(), MaterialFile::RequiredPredefinedMethodType::Light) != materialFile->RequiredMethods.end())
			{
				if (stage == 0)
				{
					maincode << HLSL::material_light_vs;
				}
				else
				{
					maincode << HLSL::material_light_ps;
				}
			}

			auto baseCode = std::string(materialFile->GetGenericCode());
			baseCode = Replace(baseCode, "$F1$", "float");
			baseCode = Replace(baseCode, "$F2$", "float2");
			baseCode = Replace(baseCode, "$F3$", "float3");
			baseCode = Replace(baseCode, "$F4$", "float4");
			baseCode = Replace(baseCode, "$TIME$", "predefined_uniform.x");
			baseCode = Replace(baseCode, "$EFFECTSCALE$", "predefined_uniform.y");
			baseCode = Replace(baseCode, "$LOCALTIME$", "predefined_uniform.w");
			baseCode = Replace(baseCode, "$UV$", "uv");
			baseCode = Replace(baseCode, "$MOD", "fmod");

			// replace textures
			for (int32_t i = 0; i < actualTextureCount; i++)
			{

				std::string prefix;
				std::string suffix;

				if (materialFile->GetTextureColorType(i) == Effekseer::TextureColorType::Color)
				{
					prefix = "ConvertFromSRGBTexture(";
					suffix = ")";
				}

				std::string keyP = "$TEX_P" + std::to_string(materialFile->GetTextureIndex(i)) + "$";
				std::string keyS = "$TEX_S" + std::to_string(materialFile->GetTextureIndex(i)) + "$";

				if (target_ == ShaderGeneratorTarget::DirectX9)
				{
					if (stage == 0)
					{
						baseCode = Replace(baseCode, keyP, prefix + std::string("tex2Dlod(") + materialFile->GetTextureName(i) + "_sampler,float4(GetUV(");
						baseCode = Replace(baseCode, keyS, "),0,1))" + suffix);
					}
					else
					{
						baseCode = Replace(baseCode, keyP, prefix + std::string("tex2D(") + materialFile->GetTextureName(i) + "_sampler,GetUV(");
						baseCode = Replace(baseCode, keyS, "))" + suffix);
					}
				}
				else
				{
					if (stage == 0)
					{
						baseCode = Replace(baseCode,
										   keyP,
										   prefix + std::string(materialFile->GetTextureName(i)) + "_texture.SampleLevel(" +
											   materialFile->GetTextureName(i) + "_sampler,GetUV(");
						baseCode = Replace(baseCode, keyS, "),0)" + suffix);
					}
					else
					{
						baseCode = Replace(baseCode,
										   keyP,
										   prefix + std::string(materialFile->GetTextureName(i)) + "_texture.Sample(" + materialFile->GetTextureName(i) +
											   "_sampler,GetUV(");
						baseCode = Replace(baseCode, keyS, "))" + suffix);
					}
				}
			}

			// invalid texture
			for (int32_t i = actualTextureCount; i < materialFile->GetTextureCount(); i++)
			{
				auto textureIndex = materialFile->GetTextureIndex(i);
				auto textureName = std::string(materialFile->GetTextureName(i));

				std::string keyP = "$TEX_P" + std::to_string(textureIndex) + "$";
				std::string keyS = "$TEX_S" + std::to_string(textureIndex) + "$";

				baseCode = Replace(baseCode, keyP, "float4(");
				baseCode = Replace(baseCode, keyS, ",0.0,1.0)");
			}

			maincode << common_functions_;

			if (stage == 0)
			{
				maincode << common_vs_define_;
			}

			ExportMain(maincode, materialFile, stage, isSprite, shaderType, baseCode);

			if (stage == 0)
			{
				shaderData.CodeVS = maincode.str();
			}
			else
			{
				shaderData.CodePS = maincode.str();
			}
		}

		// custom data
		int32_t inputSlot = 2;
		int32_t outputSlot = 7;
		if (materialFile->GetCustomData1Count() > 0)
		{
			if (isSprite)
			{
				shaderData.CodeVS =
					Replace(shaderData.CodeVS,
							"//$C_IN1$",
							GetType(materialFile->GetCustomData1Count()) + " CustomData1 : TEXCOORD" + std::to_string(inputSlot) + ";");
			}

			shaderData.CodeVS =
				Replace(shaderData.CodeVS,
						"//$C_OUT1$",
						GetType(materialFile->GetCustomData1Count()) + " CustomData1 : TEXCOORD" + std::to_string(outputSlot) + ";");
			shaderData.CodePS =
				Replace(shaderData.CodePS,
						"//$C_PIN1$",
						GetType(materialFile->GetCustomData1Count()) + " CustomData1 : TEXCOORD" + std::to_string(outputSlot) + ";");

			inputSlot++;
			outputSlot++;
		}

		if (materialFile->GetCustomData2Count() > 0)
		{
			if (isSprite)
			{
				shaderData.CodeVS =
					Replace(shaderData.CodeVS,
							"//$C_IN2$",
							GetType(materialFile->GetCustomData2Count()) + " CustomData2 : TEXCOORD" + std::to_string(inputSlot) + ";");
			}
			shaderData.CodeVS =
				Replace(shaderData.CodeVS,
						"//$C_OUT2$",
						GetType(materialFile->GetCustomData2Count()) + " CustomData2 : TEXCOORD" + std::to_string(outputSlot) + ";");
			shaderData.CodePS =
				Replace(shaderData.CodePS,
						"//$C_PIN2$",
						GetType(materialFile->GetCustomData2Count()) + " CustomData2 : TEXCOORD" + std::to_string(outputSlot) + ";");
		}

		return shaderData;
	}
};

} // namespace DirectX

} // namespace Effekseer