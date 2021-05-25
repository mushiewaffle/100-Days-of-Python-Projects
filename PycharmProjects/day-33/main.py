import requests
from datetime import datetime

MY_LAT = 37.658428
MY_LNG = -121.876999

params = {
    "lat": MY_LAT,
    "lng": MY_LNG,
    "formatted": 0
}

response = requests.get(url = "https://api.sunrise-sunset.org/json", params=params)
response.raise_for_status()
data = response.json()

sunrise_time = int(data['results']['sunrise'].split("T")[1].split(":")[0])
sunset_time = int(data['results']['sunset'].split("T")[1].split(":")[0])

time_now = datetime.utcnow().hour

print(time_now)
print(sunrise_time, sunset_time)

if time_now >= 12 or time_now<= 3:
    print('Day time')
else:
    print('Night time')