#include <memory>
#include <print>
class Pizza
{
public:
  virtual std::string description() const = 0;
  virtual double price() const = 0;
  virtual ~Pizza() = default;
};

class MargheritaPizza : public Pizza
{
public:
  std::string description() const override
  {
    return "Margherita Pizza";
  }

  double price() const override
  {
    return 9.99;
  }
};

class HawaiianPizza : public Pizza
{
public:
  std::string description() const override
  {
    return "Hawaiian Pizza";
  }

  double price() const override
  {
    return 11.99;
  }
};

class PepperoniPizza : public Pizza
{
public:
  std::string description() const override
  {
    return "Pepperoni Pizza";
  }

  double price() const override
  {
    return 12.99;
  }
};

class ToppingDecorator : public Pizza
{
public:
  explicit ToppingDecorator(std::unique_ptr<Pizza> pizza) : m_Pizza(std::move(pizza)) {}

  std::string description() const override
  {
    return m_Pizza->description();
  }

  double price() const override
  {
    return m_Pizza->price();
  }

  virtual ~ToppingDecorator() = default;

private:
  const std::unique_ptr<Pizza> m_Pizza;
};

class MushroomDecorator : public ToppingDecorator
{
public:
  explicit MushroomDecorator(std::unique_ptr<Pizza> pizza) : ToppingDecorator(std::move(pizza)) {}

  std::string description() const override
  {
    return ToppingDecorator::description() + " with mushrooms";
  }

  double price() const override
  {
    return ToppingDecorator::price() + 0.99;
  }
};

class ExtraCheeseDecorator : public ToppingDecorator
{
public:
  explicit ExtraCheeseDecorator(std::unique_ptr<Pizza> pizza) : ToppingDecorator(std::move(pizza)) {}

  std::string description() const override
  {
    return ToppingDecorator::description() + ", plus extra cheese";
  }

  double price() const override
  {
    return ToppingDecorator::price() + 1.99;
  }
};

class TomatoDecorator : public ToppingDecorator
{
public:
  explicit TomatoDecorator(std::unique_ptr<Pizza> pizza) : ToppingDecorator(std::move(pizza)) {}

  std::string description() const override
  {
    return ToppingDecorator::description() + ", plus tomatoes";
  }

  double price() const override
  {
    return ToppingDecorator::price() + 0.79;
  }
};

int main()
{
  // MargheritaPizza with mushrooms and extra cheese
  auto margheritaPizza = std::make_unique<MargheritaPizza>();
  auto margheritaWithMushrooms = std::make_unique<MushroomDecorator>(std::move(margheritaPizza));
  auto margheritaExtraCheeseMushrooms = std::make_unique<ExtraCheeseDecorator>(std::move(margheritaWithMushrooms));

  std::print("{} costs ${}\n", margheritaExtraCheeseMushrooms->description(), margheritaExtraCheeseMushrooms->price());

  // Pepperoni pizza with mushrooms, tomatoes, and extra cheese
  auto pepperoniPizza = std::make_unique<PepperoniPizza>();
  auto pepperoniWithMushrooms = std::make_unique<MushroomDecorator>(std::move(pepperoniPizza));
  auto pepperoniWithTomatoMushrooms = std::make_unique<TomatoDecorator>(std::move(pepperoniWithMushrooms));
  auto pepperoniTomatoMushroomsExtraCheese = std::make_unique<ExtraCheeseDecorator>(std::move(pepperoniWithTomatoMushrooms));

  std::print("{} costs ${}\n", pepperoniTomatoMushroomsExtraCheese->description(), pepperoniTomatoMushroomsExtraCheese->price());

  return 0;
}