const char setParamsJS[] PROGMEM = R"=====(
  function setParams(data){
    console.log('Params: heating temp1: ' + data.heatingStateTemp1Min);
    document.querySelector('#heatingTemp1Min').value = data.heatingStateTemp1Min;
    document.querySelector('#heatingTemp1Max').value = data.heatingStateTemp1Max;
    document.querySelector('#heatingTemp2Min').value = data.heatingStateTemp2Min;
    document.querySelector('#heatingTemp2Max').value = data.heatingStateTemp2Max;
    if ((data.heatingStateMainPower == 1)||(data.heatingStateMainPower == true)){
       document.getElementById('heatingMainPowerOn').checked = true;
    } else{
       document.getElementById('heatingMainPowerOff').checked = true
    };
    if ((data.heatingStateAddPower == 1)||(data.heatingStateAddPower == true)){
       document.getElementById('heatingAddPowerOn').checked = true;
    } else{
       document.getElementById('heatingAddPowerOff').checked = true
    };
    document.querySelector('#onFirstTemp1Min').value = data.onFirstStateTemp1Min;
    document.querySelector('#onFirstTemp1Max').value = data.onFirstStateTemp1Max;
    document.querySelector('#onFirstTemp2Min').value = data.onFirstStateTemp2Min;
    document.querySelector('#onFirstTemp2Max').value = data.onFirstStateTemp2Max;
    if ((data.onFirstStateMainPower == 1)||(data.onFirstStateMainPower == true)){
       document.getElementById('onFirstMainPowerOn').checked = true;
    } else{
       document.getElementById('onFirstMainPowerOff').checked = true
    };
    if ((data.onFirstStateAddPower == 1)||(data.onFirstStateAddPower == true)){
       document.getElementById('onFirstAddPowerOn').checked = true;
    } else{
       document.getElementById('onFirstAddPowerOff').checked = true
    };
    document.querySelector('#onSecondTemp1Min').value = data.onSecondStateTemp1Min;
    document.querySelector('#onSecondTemp1Max').value = data.onSecondStateTemp1Max;
    document.querySelector('#onSecondTemp2Min').value = data.onSecondStateTemp2Min;
    document.querySelector('#onSecondTemp2Max').value = data.onSecondStateTemp2Max;
    if ((data.onSecondStateMainPower == 1)||(data.onSecondStateMainPower == true)){
       document.getElementById('onSecondMainPowerOn').checked = true;
    } else{
       document.getElementById('onSecondMainPowerOff').checked = true
    };
    if ((data.onSecondStateAddPower == 1)||(data.onSecondStateAddPower == true)){
       document.getElementById('onSecondAddPowerOn').checked = true;
    } else{
       document.getElementById('onSecondAddPowerOff').checked = true
    };
    document.querySelector('#onThirdTemp1Min').value = data.onThirdStateTemp1Min;
    document.querySelector('#onThirdTemp1Max').value = data.onThirdStateTemp1Max;
    document.querySelector('#onThirdTemp2Min').value = data.onThirdStateTemp2Min;
    document.querySelector('#onThirdTemp2Max').value = data.onThirdStateTemp2Max;
    if ((data.onThirdStateMainPower == 1)||(data.onThirdStateMainPower == true)){
       document.getElementById('onThirdMainPowerOn').checked = true;
    } else{
       document.getElementById('onThirdMainPowerOff').checked = true
    };
    if ((data.onThirdStateAddPower == 1)||(data.onThirdStateAddPower == true)){
      document.getElementById('onThirdAddPowerOn').checked = true;
   } else{
      document.getElementById('onThirdAddPowerOff').checked = true;
   };
   document.querySelector('#crashTemp1Min').value = data.crashStateTemp1Min;
   document.querySelector('#crashTemp1Max').value = data.crashStateTemp1Max;
   document.querySelector('#crashTemp2Min').value = data.crashStateTemp2Min;
   document.querySelector('#crashTemp2Max').value = data.crashStateTemp2Max;
 };
)=====";
