#include <print>
#include <string>

class WorldWeatherAPI
{
public:
  std::tuple<float, float, std::string> getWeather(std::string location)
  {
    std::print("Calling worldWeather with location: {}\n", location);
    float temperature = 20.0f;
    float windSpeed = 5.5f;
    std::string shortDescription = "Sunny";
    return std::make_tuple(temperature, windSpeed, shortDescription);
  }
};

class FreeWeather
{
public:
  std::tuple<float, std::string> retrieve_weather(std::string location)
  {
    std::print("Calling Free Weather with location: {}\n", location);
    float temperature = 22.0f;
    std::string shortDescription = "Sunny";
    return std::make_tuple(temperature, shortDescription);
  }
};

class RealtimeWeatherService
{
public:
  std::tuple<float, float, std::string> weatherConditions(std::string location)
  {
    std::print("{}{}", "Calling realtimeWeather with location: ", location);
    float temperature = 19.5f;
    float humidity = 60.0f;
    std::string shortDescription = "Partly cloudy with a chance of rain";
    return std::make_tuple(temperature, humidity, shortDescription);
  }
};

class WorldWeatherFacade
{
  WorldWeatherAPI _worldWeather;
  FreeWeather _freeWeather;
  RealtimeWeatherService _realtimeWeather;

public:
  void showCurrentWeather(const std::string &location)
  {
    // Call each API and combine the results
    std::tuple<float, float, std::string> worldWeatherResult = _worldWeather.getWeather(location);
    std::tuple<float, std::string> freeWeatherResult = _freeWeather.retrieve_weather(location);
    std::tuple<float, float, std::string> realtimeWeatherResult = _realtimeWeather.weatherConditions(location);

    // Combine the results into a single string
    float temperature = std::get<0>(worldWeatherResult);
    float humidity = get<1>(realtimeWeatherResult);
    std::string shortDescription = get<1>(freeWeatherResult);

    std::print("\nWeather for {}\n{}\n{}{}{}\n{}{}%\n", location, shortDescription, "Temperature: ", temperature, " C", "Humidity: ", humidity);
  }
};
int main()
{

  std::string const location = "San Francisco, CA, US";
  WorldWeatherFacade weather;
  weather.showCurrentWeather(location);
  return 0;
}