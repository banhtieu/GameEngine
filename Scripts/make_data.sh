PROJECT_DIR=../
DATA_DIR=$PROJECT_DIR/Data
TEXT_DIR=$DATA_DIR/Text
SPRITE_DIR=$DATA_DIR/Sprites
TOOLS=$PROJECT_DIR/Tools
STRING_TOOL=$TOOLS/StringPacker/StringPacker.jar
SPRITE_TOOL=$TOOLS/SpriteEditor/SpriteEditor/Contents/MacOS/SpriteEditor
SOURCE_DIR=$PROJECT_DIR/Source/Game/Generated
BINARY_DIR=$PROJECT_DIR/Binary

echo Packing text ...

java -jar $STRING_TOOL $TEXT_DIR/Strings.xls $SOURCE_DIR/ExportedStrings.h $BINARY_DIR/strings
