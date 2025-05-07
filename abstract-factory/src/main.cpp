#include <print>
#include <memory>
#ifdef _WIN32
#define GUI WinFactory
#else
#define GUI MacFactory
#endif
// Abstract products
class Button
{
public:
  virtual void click() = 0;
};
class Checkbox
{
public:
  virtual void check() = 0;
};

// Concrete products
class WinButton : public Button
{
  void click() override { std::print("win : {}\n", __func__); }
};
class MacButton : public Button
{
  void click() override { std::print("mac : {}\n", __func__); }
};
// Concrete products
class WinCheckbox : public Checkbox
{
  void check() override { std::print("win : {}\n", __func__); }
};
class MacCheckbox : public Checkbox
{
  void check() override { std::print("mac : {}\n", __func__); }
};

// Abstract factory
class GUIFactory
{
public:
  virtual Button *createButton() = 0;
  virtual Checkbox *createCheckbox() = 0;
};

// Concrete factories
class WinFactory : public GUIFactory
{
public:
  Button *createButton() override { return new WinButton(); }
  Checkbox *createCheckbox() override { return new WinCheckbox(); }
};

class MacFactory : public GUIFactory
{
public:
  Button *createButton() override { return new MacButton(); }
  Checkbox *createCheckbox() override { return new MacCheckbox(); }
};

int main()
{
  std::unique_ptr<GUIFactory> gui = std::make_unique<GUI>();
  gui->createButton()->click();
  gui->createCheckbox()->check();
}