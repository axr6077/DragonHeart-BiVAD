#!/usr/bin/env node

var b = require('bonescript');

var pins = ["P9_33", "P9_35", "P9_36", "P9_37", "P9_38", "P9_39", "P9_40"];

var m = 0.8;
var r1 = 0.08; 
var r2 = 0.3;
var bValue = 0;
var k_p = 0.02;
var k_i = 0.00004;
var theta_setpoint = 90;
var integral_error = 0;
var previous_error = 0;
var dt = 0.001; // seconds

setInterval(function() {
  pins.forEach(function(pin) {
    var start = Date.now();
    b.analogRead(pin, function(x) {
        //var start = Date.now();
        if (x.err) {
          console.error("Error reading pin " + pin + ": " + x.err);
          return;
        }
        
        var calibrated_Volts = x.value * m + bValue;
        console.log(pin + " = " + calibrated_Volts + " volts");

        // Calculate theta
        var rVector1 = calibrated_Volts * r1;
        var rVector2 = calibrated_Volts * r2;
        var theta = (Math.atan2(-rVector2, -rVector1)) * (180/Math.PI) + 180;
        console.log("Theta = " + theta + " degrees");

        // Calculate I_R
        var error = theta_setpoint - theta;
        integral_error += error * dt;
        var I_R = k_p * error + k_i * integral_error;
        console.log("I_R = " + I_R + " amps");
        var end = Date.now(); // record end time
        var elapsed = end - start; // calculate elapsed time
        console.log("Elapsed time: " + elapsed/500000 + " ms");
    });
  });
}, 5);
