const char setSensorsDataJS[] PROGMEM = R"=====(
  function setSensorsData(data){
    console.log('Temp sensor ' + data.temp1);
    document.querySelector('#tSensor1').innerText = data.temp1;
    document.querySelector('#tSensor2').innerText = data.temp2;
    if (data.mainPower) {
       document.querySelector('#mainPower').innerText = 'Вкл.';
    } else {
       document.querySelector('#mainPower').innerText = 'Выкл.';
    };
    if (data.addPower) {
       document.querySelector('#addPower').innerText = 'Вкл.';
    } else {
       document.querySelector('#addPower').innerText = 'Выкл.';
    };
    if (data.valve1) {
       document.querySelector('#valve1').innerText = 'Откр';
    } else {
       document.querySelector('#valve1').innerText = 'Закр';
    };
    if (data.valve2) {
       document.querySelector('#valve2').innerText = 'Откр';
    } else {
       document.querySelector('#valve2').innerText = 'Закр';
    };
    if (data.valve3) {
       document.querySelector('#valve3').innerText = 'Откр';
    } else {
       document.querySelector('#valve3').innerText = 'Закр';
    };
    if (data.valve4) {
       document.querySelector('#valve4').innerText = 'Откр';
    } else {
       document.querySelector('#valve4').innerText = 'Закр';
    };
    if (data.inputLiquidLevel) {
       document.querySelector('#inputLiquidLevel').innerText = 'Полный';
    } else {
       document.querySelector('#inputLiquidLevel').innerText = 'Пустой';
    };
    if (data.outputLiquidLevel1) {
       document.querySelector('#outputLiquidLevel1').innerText = 'Полный';
    } else {
       document.querySelector('#outputLiquidLevel1').innerText = 'Пустой';
    };
    if (data.outputLiquidLevel2) {
       document.querySelector('#outputLiquidLevel2').innerText = 'Полный';
    } else {
       document.querySelector('#outputLiquidLevel2').innerText = 'Пустой';
    };
    if (data.outputLiquidLevel3) {
       document.querySelector('#outputLiquidLevel3').innerText = 'Полный';
    } else {
       document.querySelector('#outputLiquidLevel3').innerText = 'Пустой';
    };
    document.querySelector('#airHumidity').innerText = data.airHumidity;
    if (!data.smokeLevel) {
       document.querySelector('#smokeLevel').innerText = 'Норма';
    } else {
       document.querySelector('#smokeLevel').innerText = 'Задымление';
    };
    if(data.status == 30){
       document.querySelector('#status').innerText = 'Авария. Пожар';
    } else if(data.status == 31){
       document.querySelector('#status').innerText = 'Авария. Утечка';
    } else if(data.status == 32){
       document.querySelector('#status').innerText = 'Авария. Открыто несколько клапанов.';
    } else if(data.status == 33){
       document.querySelector('#status').innerText = 'Авария. Работа при закрытом клапане.';
    } else if(data.status == 3){
       document.querySelector('#status').innerText = 'Авария';
    } else if(data.status == 21){
       document.querySelector('#status').innerText = 'Работа. Отбор первой фракции.';
    } else if(data.status == 22){
       document.querySelector('#status').innerText = 'Работа. Отбор второй фракции.';
    } else if(data.status == 23){
       document.querySelector('#status').innerText = 'Работа. Отбор третей фракции.';
    } else if(data.status == 2){
       document.querySelector('#status').innerText = 'Работа';
    } else if(data.status == 1){
       document.querySelector('#status').innerText = 'Простой';
    } else {
       document.querySelector('#status').innerText = 'Не определен';
    };
  };
)=====";
