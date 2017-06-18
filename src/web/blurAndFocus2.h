const char blurAndFocus2JS[] PROGMEM = R"=====(
onSecondTemp2Max.onblur = function() {
    if ((this.value > 120)||(this.value < 0)||isNaN(this.value)||(this.value.length < 1)) {
        onSecondTemp2MaxDiv.className = "form-group has-error";
    }
};
onSecondTemp2Max.onfocus = function() {
    if (onSecondTemp2MaxDiv.className == 'form-group has-error') {
        onSecondTemp2MaxDiv.className = "form-group";
    }
};
onThirdTemp2Min.onblur = function() {
    if ((this.value > 120)||(this.value < 0)||isNaN(this.value)||(this.value.length < 1)) {
        onThirdTemp2MinDiv.className = "form-group has-error";
    }
};
onThirdTemp2Min.onfocus = function() {
    if (onThirdTemp2MinDiv.className == 'form-group has-error') {
        onThirdTemp2MinDiv.className = "form-group";
    }
};
onThirdTemp2Max.onblur = function() {
    if ((this.value > 120)||(this.value < 0)||isNaN(this.value)||(this.value.length < 1)) {
        onThirdTemp2MaxDiv.className = "form-group has-error";
    }
};
onThirdTemp2Max.onfocus = function() {
    if (onThirdTemp2MaxDiv.className == 'form-group has-error') {
        onThirdTemp2MaxDiv.className = "form-group";
    }
};
crashTemp2Min.onblur = function() {
    if ((this.value > 120)||(this.value < 0)||isNaN(this.value)||(this.value.length < 1)) {
        crashTemp2MinDiv.className = "form-group has-error";
    }
};
crashTemp2Min.onfocus = function() {
    if (crashTemp2MinDiv.className == 'form-group has-error') {
        crashTemp2MinDiv.className = "form-group";
    }
};
crashTemp2Max.onblur = function() {
    if ((this.value > 120)||(this.value < 0)||isNaN(this.value)||(this.value.length < 1)) {
        crashTemp2MaxDiv.className = "form-group has-error";
    }
};
crashTemp2Max.onfocus = function() {
    if (crashTemp2MaxDiv.className == 'form-group has-error') {
        crashTemp2MaxDiv.className = "form-group";
    }
};
heatingMainPowerOn.onblur = function() {
    if (!Array.prototype.filter.call(document.getElementsByName('heatingMainPower'), function(elem){return elem.checked;}).length) {
        heatingMainPowerOnDiv.className = "radio has-error";
        heatingMainPowerOffDiv.className = "radio has-error";
    }
};
heatingMainPowerOn.onfocus = function() {
    heatingMainPowerOnDiv.className = "radio";
    heatingMainPowerOffDiv.className = "radio";
};
heatingMainPowerOff.onfocus = function() {
    heatingMainPowerOnDiv.className = "radio";
    heatingMainPowerOffDiv.className = "radio";
};
onFirstMainPowerOn.onblur = function() {
    if (!Array.prototype.filter.call(document.getElementsByName('onFirstMainPower'), function(elem){return elem.checked;}).length) {
        onFirstMainPowerOnDiv.className = "radio has-error";
        onFirstMainPowerOffDiv.className = "radio has-error";
    }
};
onFirstMainPowerOn.onfocus = function() {
    onFirstMainPowerOnDiv.className = "radio";
    onFirstMainPowerOffDiv.className = "radio";
};
onFirstMainPowerOff.onfocus = function() {
    onFirstMainPowerOnDiv.className = "radio";
    onFirstMainPowerOffDiv.className = "radio";
};
onSecondMainPowerOn.onblur = function() {
    if (!Array.prototype.filter.call(document.getElementsByName('onSecondMainPower'), function(elem){return elem.checked;}).length) {
        onSecondMainPowerOnDiv.className = "radio has-error";
        onSecondMainPowerOffDiv.className = "radio has-error";
    }
};
onSecondMainPowerOn.onfocus = function() {
    onSecondMainPowerOnDiv.className = "radio";
    onSecondMainPowerOffDiv.className = "radio";
};
onSecondMainPowerOff.onfocus = function() {
    onSecondMainPowerOnDiv.className = "radio";
    onSecondMainPowerOffDiv.className = "radio";
};
onThirdMainPowerOn.onblur = function() {
    if (!Array.prototype.filter.call(document.getElementsByName('onThirdMainPower'), function(elem){return elem.checked;}).length) {
        onThirdMainPowerOnDiv.className = "radio has-error";
        onThirdMainPowerOffDiv.className = "radio has-error";
    }
};
onThirdMainPowerOn.onfocus = function() {
    onThirdMainPowerOnDiv.className = "radio";
    onThirdMainPowerOffDiv.className = "radio";
};
onThirdMainPowerOff.onfocus = function() {
    onThirdMainPowerOnDiv.className = "radio";
    onThirdMainPowerOffDiv.className = "radio";
};
heatingAddPowerOn.onblur = function() {
    if (!Array.prototype.filter.call(document.getElementsByName('heatingAddPower'), function(elem){return elem.checked;}).length) {
        heatingAddPowerOnDiv.className = "radio has-error";
        heatingAddPowerOffDiv.className = "radio has-error";
    }
};
heatingAddPowerOn.onfocus = function() {
    heatingAddPowerOnDiv.className = "radio";
    heatingAddPowerOffDiv.className = "radio";
};
heatingAddPowerOff.onfocus = function() {
    heatingAddPowerOnDiv.className = "radio";
    heatingAddPowerOffDiv.className = "radio";
};
onFirstAddPowerOn.onblur = function() {
    if (!Array.prototype.filter.call(document.getElementsByName('onFirstAddPower'), function(elem){return elem.checked;}).length) {
        onFirstAddPowerOnDiv.className = "radio has-error";
        onFirstAddPowerOffDiv.className = "radio has-error";
    }
};
onFirstAddPowerOn.onfocus = function() {
    onFirstAddPowerOnDiv.className = "radio";
    onFirstAddPowerOffDiv.className = "radio";
};
onFirstAddPowerOff.onfocus = function() {
    onFirstAddPowerOnDiv.className = "radio";
    onFirstAddPowerOffDiv.className = "radio";
};
onSecondAddPowerOn.onblur = function() {
    if (!Array.prototype.filter.call(document.getElementsByName('onSecondAddPower'), function(elem){return elem.checked;}).length) {
        onSecondAddPowerOnDiv.className = "radio has-error";
        onSecondAddPowerOffDiv.className = "radio has-error";
    }
};
onSecondAddPowerOn.onfocus = function() {
    onSecondAddPowerOnDiv.className = "radio";
    onSecondAddPowerOffDiv.className = "radio";
};
onSecondAddPowerOff.onfocus = function() {
    onSecondAddPowerOnDiv.className = "radio";
    onSecondAddPowerOffDiv.className = "radio";
};
onThirdAddPowerOn.onblur = function() {
    if (!Array.prototype.filter.call(document.getElementsByName('onThirdAddPower'), function(elem){return elem.checked;}).length) {
        onThirdAddPowerOnDiv.className = "radio has-error";
        onThirdAddPowerOffDiv.className = "radio has-error";
    }
};
onThirdAddPowerOn.onfocus = function() {
    onThirdAddPowerOnDiv.className = "radio";
    onThirdAddPowerOffDiv.className = "radio";
};
onThirdAddPowerOff.onfocus = function() {
    onThirdAddPowerOnDiv.className = "radio";
    onThirdAddPowerOffDiv.className = "radio";
};
)=====";
