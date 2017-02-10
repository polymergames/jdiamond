
#include "CD_Engine2D.h"
#include "CD_Physics2D.h"
#include "CD_Transform2.h"

int main(int argc, char *argv[]) {
    if (dEngine2DInit()) {
        if (dPhysics2DInit()) {
            auto transform = dTransform2MakeTransform(
                200, 200, 0, 1, 1
            );
            auto rigidbody = dPhysics2DMakeRigidbody(transform);

            dPhysics2DDestroy();
        }
        else {
            std::cout << "Failed to init physics!" << std::endl;
        }

        dEngine2DDestroy();
    }
    else {
        std::cout << "Failed to init engine!" << std::endl;
    }
    return 0;
}
