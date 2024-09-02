#define NOMINMAX
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <pxr/usd/usd/stage.h>
#include <pxr/usd/usd/prim.h>
#include <pxr/usd/usdGeom/mesh.h>
#include <pxr/base/gf/vec3f.h>
#include <pxr/pxr.h>
#include "testing.h"

PXR_NAMESPACE_USING_DIRECTIVE

int main(int argc, char* argv[]) {
	
	
	std::cout << "Hello world!" << std::endl;
	double value = 1.0;
	double result = std::sin(value);

	std::cout << "The sin of " << value << " is " << result << std::endl;

    std::string testingPath = "C:\Users\Seth\Documents\Room.usdz";

	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <USD file path>" << std::endl;
		return 1;

	}
	std::string usdFilePath = argv[1];
	OpenUsdFile(usdFilePath);
}


void OpenUsdFile(const std::string& filePath) {
    

    // Open the USD stage
    SdfPath rootPath = SdfPath::AbsoluteRootPath();
    UsdStageRefPtr stage = UsdStage::Open(filePath);

    if (!stage) {
        std::cerr << "Failed to open USD file: " << filePath << std::endl;
        return;
    }

    // Get the root layer of the USD stage
    const SdfLayerHandle& rootLayer = stage->GetRootLayer();

    if (!rootLayer) {
        std::cerr << "Root layer is null" << std::endl;
        return;
    }

    // Print some information about the USD file
    std::cout << "Successfully opened USD file: " << filePath << std::endl;
    std::cout << "Root Layer Path: " << rootLayer->GetIdentifier() << std::endl;
    std::cout << "Number of SubLayers: " << rootLayer->GetSubLayerPaths().size() << std::endl;

    // Example: Print the top-level USD stage's stage name
    std::cout << "Stage Name: " << stage->GetRootLayer()->GetDisplayName() << std::endl;
	
}