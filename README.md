# SIGFOX connected mailbox

## Description
The Arduino sketch turns your plain old mailbox into a **connected** device with a **very low power** consumption.
Thus, when the postman puts letters in your mailbox, it automatically sends a [Pushbullet](https://www.pushbullet.com/) notification.

Note that :
- the prototype is based on an [Akeru evaluation board](http://akeru.cc/) (a SIGFOX enabled Arduino UNO board)
- the Arduino sleeps between two notifications to save power

<table>
<tr>
<td>
![Prototype](https://pbs.twimg.com/media/CSK5nTFWEAA5_cL.jpg "Prototype")
</td>
<td>
![Pushbullet](https://github.com/ksahnine/mailbox-sigfox/raw/master/img/pushbullet.jpeg "Pushbullet")
</td>
</tr>
</table>

## Getting the parts
- 1 Akeru EVB
- 1 Tilt sensor
- 1 Raspberry Pi (or any single board computer, or any virtual server on the Cloud)

## Architecture

![Architecture](https://github.com/ksahnine/mailbox-sigfox/raw/master/img/archi.png "Architecture")

## Arduino

### Wiring
![Tilt](https://github.com/ksahnine/mailbox-sigfox/raw/master/img/tilt.png "Tilt module")
<table>
  <tr>
    <th>Tilt pin</th><th>Arduino board</th>
  </tr>
  <tr>
    <td>V</td><td>+5V</td>
  </tr>
  <tr>
    <td>G</td><td>GND</td>
  </tr>
  <tr>
    <td>S</td><td>D2</td>
  </tr>
</table>

### Prerequisites
- [Download](https://github.com/rocketscream/Low-Power/archive/master.zip) the [Low-Power](https://github.com/rocketscream/Low-Power) library
- Save the file to the `~/Documents/Arduino/librairies` folder
- Rename the file `master.zip` to `Low-Power.zip`
- Unzip the file `Low-Power.zip`

### Installation
- Get the source code
```
git clone https://github.com/ksahnine/mailbox-sigfox.git
```
- Open the sketch `./arduino/SIGBox/SIGBox.ino` with your Arduino IDE
- Build the sketch and upload it to your board

## Backend

### Prerequisites
- Install [Flask](http://flask.pocoo.org/)
```
sudo pip install Flask
```
- Install [Pushbullet Python library](https://github.com/randomchars/pushbullet.py)
```
git clone https://github.com/randomchars/pushbullet.py.git 
cd pushbullet.py 
python ./setup.py install
```

### Installation
- Get the source code
```
git clone https://github.com/ksahnine/mailbox-sigfox.git
cd mailbox-sigfox/backend
```
- Configure your Pushbullet API key in the `conf/config.yml` file
- Start the service :
```
./app.py
```

## SIGFOX

- [Configure](https://backend.sigfox.com) the SIGFOX callback URL to `http://XX.XX.XX.XX:5000/sigbox/inbox` where `XX.XX.XX.XX` is the public IP adress of the backend server

![SIGFOX callback](https://raw.githubusercontent.com/ksahnine/mailbox-sigfox/master/img/sigbox_callback.png "Callback")

