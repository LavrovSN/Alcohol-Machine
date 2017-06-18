const char clickJS[] PROGMEM = R"=====(
  document.addEventListener('DOMContentLoaded', function (){
    console.log('Документ click загрузился');
  });
  var formData = {};
    function checkRadio(name) {
      if (document.querySelector('input[name=' + name + ']:checked').value == 'on'){
        return true;
      } else{
        return false;
      };
    };
    ok.onclick = function(){
      if (checkInput()){
        formData = {
          'heatingStateTemp1Min':document.querySelector('#heatingTemp1Min').value,
          'heatingStateTemp1Max':document.querySelector('#heatingTemp1Max').value,
          'heatingStateTemp2Min':document.querySelector('#heatingTemp2Min').value,
          'heatingStateTemp2Max':document.querySelector('#heatingTemp2Max').value,
          'heatingStateMainPower':(checkRadio('heatingMainPower')),
          'heatingStateAddPower':(checkRadio('heatingAddPower')),
          'onFirstStateTemp1Min':document.querySelector('#onFirstTemp1Min').value,
          'onFirstStateTemp1Max':document.querySelector('#onFirstTemp1Max').value,
          'onFirstStateTemp2Min':document.querySelector('#onFirstTemp2Min').value,
          'onFirstStateTemp2Max':document.querySelector('#onFirstTemp2Max').value,
          'onFirstStateMainPower':(checkRadio('onFirstMainPower')),
          'onFirstStateAddPower':(checkRadio('onFirstAddPower')),
          'onSecondStateTemp1Min':document.querySelector('#onSecondTemp1Min').value,
          'onSecondStateTemp1Max':document.querySelector('#onSecondTemp1Max').value,
          'onSecondStateTemp2Min':document.querySelector('#onSecondTemp2Min').value,
          'onSecondStateTemp2Max':document.querySelector('#onSecondTemp2Max').value,
          'onSecondStateMainPower':(checkRadio('onSecondMainPower')),
          'onSecondStateAddPower':(checkRadio('onSecondAddPower')),
          'onThirdStateTemp1Min':document.querySelector('#onThirdTemp1Min').value,
          'onThirdStateTemp1Max':document.querySelector('#onThirdTemp1Max').value,
          'onThirdStateTemp2Min':document.querySelector('#onThirdTemp2Min').value,
          'onThirdStateTemp2Max':document.querySelector('#onThirdTemp2Max').value,
          'onThirdStateMainPower':(checkRadio('onThirdMainPower')),
          'onThirdStateAddPower':(checkRadio('onThirdAddPower')),
          'crashStateTemp1Min':document.querySelector('#crashTemp1Min').value,
          'crashStateTemp1Max':document.querySelector('#crashTemp1Max').value,
          'crashStateTemp2Min':document.querySelector('#crashTemp2Min').value,
          'crashStateTemp2Max':document.querySelector('#crashTemp2Max').value
        };
        socket.send(JSON.stringify(formData));
      };
   };

   start.onclick = function(){
      console.log('Кнопка Start нажата');
      socket.send('Start');
   };
   
   stahp.onclick = function(){
      console.log('Кнопка Stop нажата');
      socket.send('Stop');
   };
)=====";
