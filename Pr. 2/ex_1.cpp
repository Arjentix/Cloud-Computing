#include <iostream>
#include <vector>
#include <string>

class Button {
 public:
  using Callback = void (*)(const Button &);

  Button(const std::string &name):
  name_(name) {
  }

  void RegisterCallback(Callback callback) {
    callbacks_.push_back(callback);
  }

  void Click() const {
    for (auto callback : callbacks_) {
      callback(*this);
    }
  }

  std::string GetName() const {
    return name_;
  }

 private:
  std::string name_;
  std::vector<Callback> callbacks_;
};

// -------------
// Запись в стандартный вывод делает функции ниже нечистыми, однако это служит
// демонстрационным целям

void ClickLogger(const Button &button) {
  std::cout << "Clicked on button " << button.GetName() << std::endl;
}

void LazyFunction(const Button &button) {
  std::cout << button.GetName() << " was clicked, but I don't wanna do anything" << std::endl;
}
// -------------

int main() {
  Button button1("Button #1");
  button1.RegisterCallback(ClickLogger);
  button1.RegisterCallback(LazyFunction);

  Button button2("Button #2");
  button2.RegisterCallback(ClickLogger);

  button1.Click();
  button2.Click();

  return 0;
}
