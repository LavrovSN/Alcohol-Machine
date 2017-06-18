const char inputCheckJS[] PROGMEM = R"=====(
function checkInput(){
    var flag = true;
    var x;
    x = document.querySelector('#heatingTemp1Min');
    if ((x.value > 120)||(x.value < 0)||isNaN(x.value)||(x.value.length < 1)) {
        heatingTemp1MinDiv.className = "form-group has-error";
        flag = false;
    } else {
        heatingTemp1MinDiv.className = "form-group";
    };
    x = document.querySelector('#heatingTemp1Max');
    if ((x.value > 120)||(x.value < 0)||isNaN(x.value)||(x.value.length < 1)) {
        heatingTemp1MaxDiv.className = "form-group has-error";
        flag = false;
    } else {
        heatingTemp1MaxDiv.className = "form-group";
    };
    x = document.querySelector('#heatingTemp2Min');
    if ((x.value > 120)||(x.value < 0)||isNaN(x.value)||(x.value.length < 1)) {
        heatingTemp2MinDiv.className = "form-group has-error";
        flag = false;
    } else {
        heatingTemp2MinDiv.className = "form-group";
    };
    x = document.querySelector('#heatingTemp2Max');
    if ((x.value > 120)||(x.value < 0)||isNaN(x.value)||(x.value.length < 1)) {
        heatingTemp2MaxDiv.className = "form-group has-error";
        flag = false;
    } else {
        heatingTemp2MaxDiv.className = "form-group";
    };
    if (!Array.prototype.filter.call(document.getElementsByName('heatingMainPower'), function(elem){return elem.checked;}).length) {
        heatingMainPowerOnDiv.className = "radio has-error";
        heatingMainPowerOffDiv.className = "radio has-error";
        flag = false;
    } else {
        heatingMainPowerOnDiv.className = "radio";
        heatingMainPowerOffDiv.className = "radio";
    };
    if (!Array.prototype.filter.call(document.getElementsByName('heatingAddPower'), function(elem){return elem.checked;}).length) {
        heatingAddPowerOnDiv.className = "radio has-error";
        heatingAddPowerOffDiv.className = "radio has-error";
        flag = false;
    } else {
        heatingAddPowerOnDiv.className = "radio";
        heatingAddPowerOffDiv.className = "radio";
    };
    x = document.querySelector('#onFirstTemp1Min');
    if ((x.value > 120)||(x.value < 0)||isNaN(x.value)||(x.value.length < 1)) {
        onFirstTemp1MinDiv.className = "form-group has-error";
        flag = false;
    } else {
        onFirstTemp1MinDiv.className = "form-group";
    };
    x = document.querySelector('#onFirstTemp1Max');
    if ((x.value > 120)||(x.value < 0)||isNaN(x.value)||(x.value.length < 1)) {
        onFirstTemp1MaxDiv.className = "form-group has-error";
        flag = false;
    } else {
        onFirstTemp1MaxDiv.className = "form-group";
    };
    x = document.querySelector('#onFirstTemp2Min');
    if ((x.value > 120)||(x.value < 0)||isNaN(x.value)||(x.value.length < 1)) {
        onFirstTemp2MinDiv.className = "form-group has-error";
        flag = false;
    } else {
        onFirstTemp2MinDiv.className = "form-group";
    };
    x = document.querySelector('#onFirstTemp2Max');
    if ((x.value > 120)||(x.value < 0)||isNaN(x.value)||(x.value.length < 1)) {
        onFirstTemp2MaxDiv.className = "form-group has-error";
        flag = false;
    } else {
        onFirstTemp2MaxDiv.className = "form-group";
    };
    if (!Array.prototype.filter.call(document.getElementsByName('onFirstMainPower'), function(elem){return elem.checked;}).length) {
        onFirstMainPowerOnDiv.className = "radio has-error";
        onFirstMainPowerOffDiv.className = "radio has-error";
        flag = false;
    } else {
        onFirstMainPowerOnDiv.className = "radio";
        onFirstMainPowerOffDiv.className = "radio";
    };
    if (!Array.prototype.filter.call(document.getElementsByName('onFirstAddPower'), function(elem){return elem.checked;}).length) {
        onFirstAddPowerOnDiv.className = "radio has-error";
        onFirstAddPowerOffDiv.className = "radio has-error";
        flag = false;
    } else {
        onFirstAddPowerOnDiv.className = "radio";
        onFirstAddPowerOffDiv.className = "radio";
    };
    x = document.querySelector('#onSecondTemp1Min');
    if ((x.value > 120)||(x.value < 0)||isNaN(x.value)||(x.value.length < 1)) {
        onSecondTemp1MinDiv.className = "form-group has-error";
        flag = false;
    } else {
        onSecondTemp1MinDiv.className = "form-group";
    };
    x = document.querySelector('#onSecondTemp1Max');
    if ((x.value > 120)||(x.value < 0)||isNaN(x.value)||(x.value.length < 1)) {
        onSecondTemp1MaxDiv.className = "form-group has-error";
        flag = false;
    } else {
        onSecondTemp1MaxDiv.className = "form-group";
    };
    x = document.querySelector('#onSecondTemp2Min');
    if ((x.value > 120)||(x.value < 0)||isNaN(x.value)||(x.value.length < 1)) {
        onSecondTemp2MinDiv.className = "form-group has-error";
        flag = false;
    } else {
        onSecondTemp2MinDiv.className = "form-group";
    };
    x = document.querySelector('#onSecondTemp2Max');
    if ((x.value > 120)||(x.value < 0)||isNaN(x.value)||(x.value.length < 1)) {
        onSecondTemp2MaxDiv.className = "form-group has-error";
        flag = false;
    } else {
        onSecondTemp2MaxDiv.className = "form-group";
    };
    if (!Array.prototype.filter.call(document.getElementsByName('onSecondMainPower'), function(elem){return elem.checked;}).length) {
        onSecondMainPowerOnDiv.className = "radio has-error";
        onSecondMainPowerOffDiv.className = "radio has-error";
        flag = false;
    } else {
        onSecondMainPowerOnDiv.className = "radio";
        onSecondMainPowerOffDiv.className = "radio";
    };
    if (!Array.prototype.filter.call(document.getElementsByName('onSecondAddPower'), function(elem){return elem.checked;}).length) {
        onSecondAddPowerOnDiv.className = "radio has-error";
        onSecondAddPowerOffDiv.className = "radio has-error";
        flag = false;
    } else {
        onSecondAddPowerOnDiv.className = "radio";
        onSecondAddPowerOffDiv.className = "radio";
    };
    x = document.querySelector('#onThirdTemp1Min');
    if ((x.value > 120)||(x.value < 0)||isNaN(x.value)||(x.value.length < 1)) {
        onThirdTemp1MinDiv.className = "form-group has-error";
        flag = false;
    } else {
        onThirdTemp1MinDiv.className = "form-group";
    };
    x = document.querySelector('#onThirdTemp1Max');
    if ((x.value > 120)||(x.value < 0)||isNaN(x.value)||(x.value.length < 1)) {
        onThirdTemp1MaxDiv.className = "form-group has-error";
        flag = false;
    } else {
        onThirdTemp1MaxDiv.className = "form-group";
    };
    x = document.querySelector('#onThirdTemp2Min');
    if ((x.value > 120)||(x.value < 0)||isNaN(x.value)||(x.value.length < 1)) {
        onThirdTemp2MinDiv.className = "form-group has-error";
        flag = false;
    } else {
        onThirdTemp2MinDiv.className = "form-group";
    };
    x = document.querySelector('#onThirdTemp2Max');
    if ((x.value > 120)||(x.value < 0)||isNaN(x.value)||(x.value.length < 1)) {
        onThirdTemp2MaxDiv.className = "form-group has-error";
        flag = false;
    } else {
        onThirdTemp2MaxDiv.className = "form-group";
    };
    if (!Array.prototype.filter.call(document.getElementsByName('onThirdMainPower'), function(elem){return elem.checked;}).length) {
        onThirdMainPowerOnDiv.className = "radio has-error";
        onThirdMainPowerOffDiv.className = "radio has-error";
        flag = false;
    } else {
        onThirdMainPowerOnDiv.className = "radio";
        onThirdMainPowerOffDiv.className = "radio";
    };
    if (!Array.prototype.filter.call(document.getElementsByName('onThirdAddPower'), function(elem){return elem.checked;}).length) {
        onThirdAddPowerOnDiv.className = "radio has-error";
        onThirdAddPowerOffDiv.className = "radio has-error";
        flag = false;
    } else {
        onThirdAddPowerOnDiv.className = "radio";
        onThirdAddPowerOffDiv.className = "radio";
    };
    x = document.querySelector('#crashTemp1Min');
    if ((x.value > 120)||(x.value < 0)||isNaN(x.value)||(x.value.length < 1)) {
        crashTemp1MinDiv.className = "form-group has-error";
        flag = false;
    } else {
        crashTemp1MinDiv.className = "form-group";
    };
    x = document.querySelector('#crashTemp1Max');
    if ((x.value > 120)||(x.value < 0)||isNaN(x.value)||(x.value.length < 1)) {
        crashTemp1MaxDiv.className = "form-group has-error";
        flag = false;
    } else {
        crashTemp1MaxDiv.className = "form-group";
    };
    x = document.querySelector('#crashTemp2Min');
    if ((x.value > 120)||(x.value < 0)||isNaN(x.value)||(x.value.length < 1)) {
        crashTemp2MinDiv.className = "form-group has-error";
        flag = false;
    } else {
        crashTemp2MinDiv.className = "form-group";
    };
    x = document.querySelector('#crashTemp2Max');
    if ((x.value > 120)||(x.value < 0)||isNaN(x.value)||(x.value.length < 1)) {
        crashTemp2MaxDiv.className = "form-group has-error";
        flag = false;
    } else {
        crashTemp2MaxDiv.className = "form-group";
    };
    return flag;
}
)=====";
