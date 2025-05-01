// Auto Genrated C++ file by aura CLI
// None
#include <print>
#include <design-patternsconfig.h>
#include <vector>
#include <memory>
class Shape
{
public:
  virtual void draw() const = 0;
  virtual ~Shape() = default;
};

class Circle : public Shape
{
public:
  explicit Circle(const float &radius) : _radius(radius) {};
  void draw() const override
  {
    std::print("Drawing Circle of Radius {}\n", _radius);
  };

private:
  float _radius{};
};
class Square : public Shape
{
public:
  explicit Square(const float &width) : _width(width) {};
  void draw() const override
  {
    std::print("Drawing Square width of {}\n", _width);
  };

private:
  float _width{};
};
class Rectagle : public Shape
{
public:
  explicit Rectagle(const float &width, const float &height) : _width(width), _height(height) {};
  void draw() const override
  {
    std::print("Drawing Rectagle width of {}, and Height of {}\n", _width, _height);
  };

private:
  float _width{}, _height{};
};

class CompositeShape : public Shape
{
public:
  void addShape(Shape &shape)
  {
    _shapes.push_back(&shape);
  }
  void removeShape(const Shape &shape)
  {
    for (auto it = _shapes.begin(); it != _shapes.end(); ++it)
    {
      if (*it == &shape)
      {
        _shapes.erase(it);
        break;
      }
    }
  }
  void draw() const override
  {
    std::print("Composite : [\n");
    for (const auto &shape : _shapes)
    {
      shape->draw();
    };
    std::print("]\n");
  };

private:
  std::vector<Shape *> _shapes{};
};

class WeirdShape : public Shape
{
public:
  void draw() const override
  {
    std::print("it's a weird shape class\n");
  }
};

int main(int argc, char *argv[])
{
  Circle circle(25.4);
  Rectagle rect(45.3, 12.7);
  Square square(49.1);
  WeirdShape weirdShape;
  CompositeShape complexShape;
  complexShape.addShape(circle);
  complexShape.draw();
  complexShape.addShape(square);
  complexShape.addShape(rect);
  complexShape.draw();
  complexShape.removeShape(circle);
  complexShape.addShape(weirdShape);
  complexShape.draw();
  return 0;
}
