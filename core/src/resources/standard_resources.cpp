#include "standard_resources.h"
#include "resources.h"
#include "../graphics/sprite/animation.h"
#include "../graphics/sprite/sprite_sheet.h"
#include "../graphics/texture.h"
#include "../graphics/material_definition.h"

using namespace Halley;

void StandardResources::initialize(Resources& resources)
{
	resources.init<Animation>("animation");
	resources.init<SpriteSheet>("spritesheet");
	resources.init<Texture>("image");
	resources.init<MaterialDefinition>("material");
	resources.init<TextFile>("");
	resources.init<YAMLFile>("");
}
