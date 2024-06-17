// InputBox.hpp
#ifndef INPUTBOX_HPP
#define INPUTBOX_HPP

#include <functional>
#include <string>
#include "Engine/IObject.hpp"

/*
namespace Engine {
    class InputBox : public Engine::IObject {
    protected:
        std::string text;
        std::function<void(const std::string&)> onSubmit;
    public:
        InputBox(float x, float y, float w, float h);
        void Draw() const override;
        void Update(float deltaTime) override;
        void OnKeyDown(int keyCode);
        void SetOnSubmitCallback(std::function<void(const std::string&)> onSubmit);
    };
}
*/
#endif
