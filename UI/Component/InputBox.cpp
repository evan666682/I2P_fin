// InputBox.cpp
#include "Engine/IObject.hpp"
#include "Image.hpp"
#include "Engine/Point.hpp"
#include "Engine/Resources.hpp"
#include "InputBox.hpp"
#include "Label.hpp"
#include <allegro5/allegro.h>
#include <functional>
#include <memory>

/*
Engine::InputBox::InputBox(float x, float y, float w, float h) :
    IObject(x, y, w, h), text("") {
}

void Engine::InputBox::Draw() const {
    // Draw input box background
    al_draw_filled_rectangle(x, y, x + w, y + h, al_map_rgb(255, 255, 255));
    // Draw text
    al_draw_text(GameEngine::GetInstance().GetFont(), al_map_rgb(0, 0, 0), x + 5, y + 5, 0, text.c_str());
}

void Engine::InputBox::Update(float deltaTime) {
    // Handle cursor blinking or other effects
}

void Engine::InputBox::OnKeyDown(int keyCode) {
    if (keyCode == ALLEGRO_KEY_ENTER) {
        if (onSubmit) onSubmit(text);
    } else if (keyCode == ALLEGRO_KEY_BACKSPACE) {
        if (!text.empty()) text.pop_back();
    } else {
        // Handle text input, Allegro provides key codes for each key
        if ((keyCode >= ALLEGRO_KEY_A && keyCode <= ALLEGRO_KEY_Z) || 
            (keyCode >= ALLEGRO_KEY_0 && keyCode <= ALLEGRO_KEY_9)) {
            text += al_keycode_to_name(keyCode);  // This is simplified, you might need to handle shift/capslock for correct character
        }
    }
}

void Engine::InputBox::SetOnSubmitCallback(std::function<void(const std::string&)> onSubmit) {
    this->onSubmit = onSubmit;
}
*/