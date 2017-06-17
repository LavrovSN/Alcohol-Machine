const char appJS[] PROGMEM = R"=====(
  document.addEventListener('DOMContentLoaded', function (){
   console.log('Документ загрузился');
  });
  var sensorsData = {};
  var ip = location.host;
  console.log(ip);
  var socket = new WebSocket('ws://' + ip +':81');
  socket.onopen = function() {
   console.log('Соединение установлено.');
  };
  socket.onclose = function(event) {
   if (event.wasClean) {
     console.log('Соединение закрыто чисто');
   } else {
     console.log('Обрыв соединения');
   }
   console.log('Код: ' + event.code + ' причина: ' + event.reason);
  };
  socket.onmessage = function(event) {
   sensorsData = JSON.parse(event.data);
   if ('temp1' in sensorsData) {
     setSensorsData(sensorsData);
   };
   if('heatingStateTemp1Min' in sensorsData){
     console.log(sensorsData);
     setParams(sensorsData);
   };
  };
  socket.onerror = function(error) {
   console.log('Ошибка ' + error.message);
  };
  console.log('Connection started');
)=====";
