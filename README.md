# SIGFOX connected mailbox

## Description
The Arduino sketch turns your plain old mailbox into a **connected** device with a **very low power** consumption.
Thus, when the postman puts letters in your mailbox, it automatically sends a [Pushbullet](https://www.pushbullet.com/) notification.

Note that :
- the prototype is based on an [Akeru evaluation board](http://akeru.cc/) (a SIGFOX enabled Arduino UNO board)
- the Arduino sleeps between two notifications to save power

## Getting the parts
- 1 Akeru EVB
- 1 Tilt sensor
- 1 Raspberry Pi (or any single board computer, or any virtual server on the Cloud)

## Architecture
![Architecture](https://github.com/ksahnine/mailbox-sigfox/raw/master/img/archi.png "Architecture")

## Wiring
![Tilt](https://github.com/ksahnine/mailbox-sigfox/raw/master/img/tilt.png "Tilt module")
<table>
  <th>
    <td>Tilt pin</td><td>Arduino board</td>
  </th>
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

