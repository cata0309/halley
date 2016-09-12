#include "halley/tools/assets/asset_importer.h"
#include "halley/support/exception.h"
#include "importers/copy_file_importer.h"
#include "importers/font_importer.h"
#include "importers/codegen_importer.h"
#include "importers/image_importer.h"
#include "importers/animation_importer.h"
#include "importers/material_importer.h"

using namespace Halley;


AssetImporter::AssetImporter()
{
	importers[AssetType::SIMPLE_COPY] = std::make_unique<CopyFileImporter>();
	importers[AssetType::FONT] = std::make_unique<FontImporter>();
	importers[AssetType::IMAGE] = std::make_unique<ImageImporter>();
	importers[AssetType::ANIMATION] = std::make_unique<AnimationImporter>();
	importers[AssetType::MATERIAL] = std::make_unique<MaterialImporter>();
	importers[AssetType::CODEGEN] = std::make_unique<CodegenImporter>();
}

IAssetImporter& AssetImporter::getImporter(Path path) const
{
	AssetType type = AssetType::SIMPLE_COPY;
	
	auto root = path.begin()->string();
	if (root == "font") {
		type = AssetType::FONT;
	} else if (root == "image") {
		type = AssetType::IMAGE;
	} else if (root == "animation") {
		type = AssetType::ANIMATION;
	} else if (root == "material") {
		type = AssetType::MATERIAL;
	}

	return getImporter(type);
}

IAssetImporter& AssetImporter::getImporter(AssetType type) const
{
	auto i = importers.find(type);
	if (i != importers.end()) {
		return *i->second;
	} else {
		throw Exception("Unknown asset type: " + String::integerToString(int(type)));
	}
}
