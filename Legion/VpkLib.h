#pragma once

#include <cstdint>
#include <array>
#include "StringBase.h"
#include "ListBase.h"
#include "DictionaryBase.h"
#include "MemoryStream.h"
#include "FileStream.h"
#include "BinaryReader.h"

#include "RpakAssets.h"
#include "ApexAsset.h"

#include "Model.h"
#include "Exporter.h"
#include "RpakLib.h"

// A class that handles reading assets from a respawn Vpk
class VpkLib
{
public:
	VpkLib();
	~VpkLib() = default;

	// The exporter formats for models and anims
	std::unique_ptr<Assets::Exporters::Exporter> ModelExporter;
	std::unique_ptr<Assets::Exporters::Exporter> AnimExporter;

	// Initializes a model exporter
	void InitializeModelExporter(RpakModelExportFormat Format = RpakModelExportFormat::SEModel);
	// Initializes a anim exporter
	void InitializeAnimExporter(RpakAnimExportFormat Format = RpakAnimExportFormat::SEAnim);

	// Exports an on-disk mdl asset
	void ExportRMdl(const string& Asset, const string& Path);

private:
	void ParseRAnimBoneTranslationTrack(const RAnimBoneHeader& BoneFlags, const RMdlTitanfallBone& Bone, uint16_t** BoneTrackData, const std::unique_ptr<Assets::Animation>& Anim, uint32_t BoneIndex, uint32_t Frame, uint32_t FrameIndex);
	void ParseRAnimBoneRotationTrack(const RAnimBoneHeader& BoneFlags, const RMdlTitanfallBone& Bone, uint16_t** BoneTrackData, const std::unique_ptr<Assets::Animation>& Anim, uint32_t BoneIndex, uint32_t Frame, uint32_t FrameIndex);
	void ParseRAnimBoneScaleTrack(const RAnimBoneHeader& BoneFlags, uint16_t** BoneTrackData, const std::unique_ptr<Assets::Animation>& Anim, uint32_t BoneIndex, uint32_t Frame, uint32_t FrameIndex);
};