# Name: Carl Dalebout
# File: main.py

import urllib.request
import re

city_id = "4575352"
api_key = "014f77b0g63693crffcbhab9dfvb7903"
url = "http://api.openweathermap.org/data/2.5/weather?id=%s&mode=xml&units=imperial&APPID=%s"
url = url % (city_id, api_key)
xml = urllib.request.urlopen(url).read()
xml = xml.decode("utf-8")

data = list[20]
for element in range(data):
  print(element)

city = ""
country = ""
sun_rise = ""
sun_set = ""
temp = ""
temp_min = ""
temp_max = ""
temp_type = ""
feels_like = ""
humidity = ""
humidity_unit = ""
pressure = ""
pressure_unit = ""
wind_speed = ""
wind_unit = ""
wind_name = ""
wind_dir = ""
clouds = ""
vis = ""
precipitation = ""
last_updated = ""



# parsXML(xml)

# City: Columbia
# Country: US
# Sun rise: 2020-03-07T11:44:40
# Sun set: 2020-03-07T23:25:37
# Temperature: 47.82, min 43, max 53.6 fahrenheit
# Feels like: 41.41 fahrenheit
# Humidity: 43%
# Pressure: 1030 hPa
# Wind speed: 3.71 mph, Light breeze
# Wind direction: North-northeast
# Clouds: clear sky
# Visibility: 16093
# Precipitation: no
# Last update: 2020-03-08T00:17:16

print("City:", city)
print("Country:", country)
print("Sun rise:", sun_rise)
print("Sun set:", sun_set)
print("Temperature: ", temp,", min ", temp_min, ", max ", temp_max, " ",  temp_type, sep = "")
print("Feels like:", feels_like, temp_type)
print("Humidity: ", humidity, humidity_unit ,sep = "")
print("Pressure:", pressure, pressure_unit) 
print("Wind speed: ", wind_speed, " ", wind_unit, ", ", wind_name, sep= "")
print("Wind direction:", wind_dir)
print("Clouds:", clouds)
print("Visibility:", vis)
print("Last update:", last_updated)
