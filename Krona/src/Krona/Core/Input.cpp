#include "Input.h"
#include "Krona/Core/Vector2.h"

namespace Krona::Input {

    static bool keys[348];
    static bool lastKeys[348];

    static Vector2 cursorPosition = { 0.0f, 0.0f };

    void LateUpdate() {
        for (uint16_t i = 0; i < 348; i++)
            lastKeys[i] = keys[i];
    }

    void SetKey(uint16_t key, bool state) {
        keys[key] = state;
    }

    void SetCursorPos(float x, float y) {
        cursorPosition.x = x;
        cursorPosition.y = y;
    }
    
    bool GetKey(uint16_t key) {
        return keys[key];
    }

    bool GetKeyDown(uint16_t key) {
        return keys[key] && !lastKeys[key];
    }

    bool GetKeyUp(uint16_t key) {
        return !keys[key] && lastKeys[key];
    }

    Vector2 GetCursorPosition() {
        return cursorPosition;
    }

    float GetX() {
        return cursorPosition.x;
    }

    float GetY() {
        return cursorPosition.y;
    }

}
