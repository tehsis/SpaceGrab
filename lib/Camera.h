#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Aliases.h"

using namespace Tehsis;

namespace Tehsis {
    class Camera {
        Rectangle* rect;
        public:
        Camera(unsigned x, unsigned y, unsigned width, unsigned height);
        Rectangle* GetRelativeRect(const Rectangle* src);
        void Move(unsigned x, unsigned y);
        unsigned int getWidth();
        unsigned int getHeight();
    };
}

#endif
