#include "InputBuffer.h"

void InputBuffer::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode == 8) {
            if (!input.empty())
                input.pop_back();
        } else if (event.text.unicode >= 32 && event.text.unicode < 128) {
            input += static_cast<char>(event.text.unicode);
        }
    }
}

void InputBuffer::clear() {
    input.clear();
}

const std::string& InputBuffer::getText() const {
    return input;
}
