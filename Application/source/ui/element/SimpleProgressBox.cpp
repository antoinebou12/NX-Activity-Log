#include "ui/element/SimpleProgressBox.hpp"

#define WIDTH 560

namespace CustomScreen {
    SimpleProgressBox::SimpleProgressBox() : Aether::Screen() {
        // Create background rectangle
        this->rect = new Aether::Rectangle((this->w() - WIDTH)/2, this->h()/2, WIDTH, 1, 8);
        this->addElement(this->rect);

        // Create heading
        this->heading = new Aether::TextBlock(this->rect->x() + 50, this->rect->y() + 35, "|", 24, this->rect->w() - 100);
        this->addElement(this->heading);

        // Create progress bar
        this->bar = new Aether::RoundProgressBar(this->heading->x(), this->heading->y() + this->heading->h() + 25, this->rect->w() - 160);
        this->bar->setValue(0);
        this->addElement(this->bar);

        // Resize rectangle + position elements
        this->rect->setRectSize(this->rect->w(), (this->bar->y() + this->bar->h()) - this->heading->y() + 75);
        this->rect->setY((this->h() - this->rect->h())/2);
        this->heading->setY(this->heading->y() - this->rect->h()/2);
        this->bar->setY(this->bar->y() - this->rect->h()/2);
    }

    void SimpleProgressBox::setHeading(const std::string & str) {
        this->heading->setString(str);
    }

    void SimpleProgressBox::setValue(const double value) {
        this->bar->setValue(value);
    }

    void SimpleProgressBox::setBackgroundColour(const Aether::Colour c) {
        this->rect->setColour(c);
    }

    void SimpleProgressBox::setBarBackgroundColour(const Aether::Colour c) {
        this->bar->setBackgroundColour(c);
    }

    void SimpleProgressBox::setBarForegroundColour(const Aether::Colour c) {
        this->bar->setForegroundColour(c);
    }

    void SimpleProgressBox::setTextColour(const Aether::Colour c) {
        this->heading->setColour(c);
    }

    void SimpleProgressBox::close() {
        // Hide the progress box by removing all elements
        this->removeAllElements();
    }
};
