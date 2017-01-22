function locationSuccess(pos) {
  var coordinates = pos.coords;
    console.log('lat= ' + pos.coords.latitude + ' lon= ' + pos.coords.longitude);
  
  //fetchWeather(coordinates.latitude, coordinates.longitude);
}

function locationError(err) {
  console.warn('location error (' + err.code + '): ' + err.message);
  Pebble.sendAppMessage({
    'Lat': 'Fail',
    'Long': 'Fail'
  });
}

var locationOptions = {
  enableHighAccuracy: true,
  maximumAge: 15000,
  timeout: 60000
};

Pebble.addEventListener('ready', function() {
  // PebbleKit JS is ready!
    navigator.geolocation.getCurrentPosition(locationSuccess, locationError,
    locationOptions);
Pebble.sendAppMessage({'JSReady': 1});
  console.log('PebbleKit JS ready!');
});

Pebble.addEventListener('appmessage', function () {
  var coordinates = pos.coords;
    console.log('lat= ' + pos.coords.latitude + ' lon= ' + pos.coords.longitude);
  Pebble.sendAppMessage({'JSReady': 1});
  console.log('message!');
});


//var dict = {
//  'Temperature': 29,
//  'LocationName': 'London, UK'
//};

// Send the object
//Pebble.sendAppMessage(dict, function() {
//  console.log('Message sent successfully: ' + JSON.stringify(dict));
//}, function(e) {
//  console.log('Message failed: ' + JSON.stringify(e));
//});