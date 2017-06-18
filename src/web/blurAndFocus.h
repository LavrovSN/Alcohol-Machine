const char blurAndFocusJS[] PROGMEM = R"=====(
  heatingTemp1Min.onblur = function() {
      if ((this.value > 120)||(this.value < 0)||isNaN(this.value)||(this.value.length <1 )) {
          heatingTemp1MinDiv.className = "form-group has-error";
      }
  };
  heatingTemp1Min.onfocus = function() {
      if (heatingTemp1MinDiv.className == 'form-group has-error') {
          heatingTemp1MinDiv.className = "form-group";
      }
  };
  heatingTemp1Max.onblur = function() {
      if ((this.value > 120)||(this.value < 0)||isNaN(this.value)||(this.value.length < 1)) {
          heatingTemp1MaxDiv.className = "form-group has-error";
      }
  };
  heatingTemp1Max.onfocus = function() {
      if (heatingTemp1MaxDiv.className == 'form-group has-error') {
          heatingTemp1MaxDiv.className = "form-group";
      }
  };
  onFirstTemp1Min.onblur = function() {
      if ((this.value > 120)||(this.value < 0)||isNaN(this.value)||(this.value.length < 1)) {
          onFirstTemp1MinDiv.className = "form-group has-error";
      }
  };
  onFirstTemp1Min.onfocus = function() {
      if (onFirstTemp1MinDiv.className == 'form-group has-error') {
          onFirstTemp1MinDiv.className = "form-group";
      }
  };
  onFirstTemp1Max.onblur = function() {
      if ((this.value > 120)||(this.value < 0)||isNaN(this.value)||(this.value.length < 1)) {
          onFirstTemp1MaxDiv.className = "form-group has-error";
      }
  };
  onFirstTemp1Max.onfocus = function() {
      if (onFirstTemp1MaxDiv.className == 'form-group has-error') {
          onFirstTemp1MaxDiv.className = "form-group";
      }
  };
  onSecondTemp1Min.onblur = function() {
      if ((this.value > 120)||(this.value < 0)||isNaN(this.value)||(this.value.length < 1)) {
          onSecondTemp1MinDiv.className = "form-group has-error";
      }
  };
  onSecondTemp1Min.onfocus = function() {
      if (onSecondTemp1MinDiv.className == 'form-group has-error') {
          onSecondTemp1MinDiv.className = "form-group";
      }
  };
  onSecondTemp1Max.onblur = function() {
      if ((this.value > 120)||(this.value < 0)||isNaN(this.value)||(this.value.length < 1)) {
          onSecondTemp1MaxDiv.className = "form-group has-error";
      }
  };
  onSecondTemp1Max.onfocus = function() {
      if (onSecondTemp1MaxDiv.className == 'form-group has-error') {
          onSecondTemp1MaxDiv.className = "form-group";
      }
  };
  onThirdTemp1Min.onblur = function() {
      if ((this.value > 120)||(this.value < 0)||isNaN(this.value)||(this.value.length < 1)) {
          onThirdTemp1MinDiv.className = "form-group has-error";
      }
  };
  onThirdTemp1Min.onfocus = function() {
      if (onThirdTemp1MinDiv.className == 'form-group has-error') {
          onThirdTemp1MinDiv.className = "form-group";
      }
  };
  onThirdTemp1Max.onblur = function() {
      if ((this.value > 120)||(this.value < 0)||isNaN(this.value)||(this.value.length < 1)) {
          onThirdTemp1MaxDiv.className = "form-group has-error";
      }
  };
  onThirdTemp1Max.onfocus = function() {
      if (onThirdTemp1MaxDiv.className == 'form-group has-error') {
          onThirdTemp1MaxDiv.className = "form-group";
      }
  };
  crashTemp1Min.onblur = function() {
      if ((this.value > 120)||(this.value < 0)||isNaN(this.value)||(this.value.length < 1)) {
          crashTemp1MinDiv.className = "form-group has-error";
      }
  };
  crashTemp1Min.onfocus = function() {
      if (crashTemp1MinDiv.className == 'form-group has-error') {
          crashTemp1MinDiv.className = "form-group";
      }
  };
  crashTemp1Max.onblur = function() {
      if ((this.value > 120)||(this.value < 0)||isNaN(this.value)||(this.value.length < 1)) {
          crashTemp1MaxDiv.className = "form-group has-error";
      }
  };
  crashTemp1Max.onfocus = function() {
      if (crashTemp1MaxDiv.className == 'form-group has-error') {
          crashTemp1MaxDiv.className = "form-group";
      }
  };
  heatingTemp2Min.onblur = function() {
      if ((this.value > 120)||(this.value < 0)||isNaN(this.value)||(this.value.length < 1)) {
          heatingTemp2MinDiv.className = "form-group has-error";
      }
  };
  heatingTemp2Min.onfocus = function() {
      if (heatingTemp2MinDiv.className == 'form-group has-error') {
          heatingTemp2MinDiv.className = "form-group";
      }
  };
  heatingTemp2Max.onblur = function() {
      if ((this.value > 120)||(this.value < 0)||isNaN(this.value)||(this.value.length < 1)) {
          heatingTemp2MaxDiv.className = "form-group has-error";
      }
  };
  heatingTemp2Max.onfocus = function() {
      if (heatingTemp2MaxDiv.className == 'form-group has-error') {
          heatingTemp2MaxDiv.className = "form-group";
      }
  };
  onFirstTemp2Min.onblur = function() {
      if ((this.value > 120)||(this.value < 0)||isNaN(this.value)||(this.value.length < 1)) {
          onFirstTemp2MinDiv.className = "form-group has-error";
      }
  };
  onFirstTemp2Min.onfocus = function() {
      if (onFirstTemp2MinDiv.className == 'form-group has-error') {
          onFirstTemp2MinDiv.className = "form-group";
      }
  };
  onFirstTemp2Max.onblur = function() {
      if ((this.value > 120)||(this.value < 0)||isNaN(this.value)||(this.value.length < 1)) {
          onFirstTemp2MaxDiv.className = "form-group has-error";
      }
  };
  onFirstTemp2Max.onfocus = function() {
      if (onFirstTemp2MaxDiv.className == 'form-group has-error') {
          onFirstTemp2MaxDiv.className = "form-group";
      }
  };
  onSecondTemp2Min.onblur = function() {
      if ((this.value > 120)||(this.value < 0)||isNaN(this.value)||(this.value.length < 1)) {
          onSecondTemp2MinDiv.className = "form-group has-error";
      }
  };
  onSecondTemp2Min.onfocus = function() {
      if (onSecondTemp2MinDiv.className == 'form-group has-error') {
          onSecondTemp2MinDiv.className = "form-group";
      }
  };
)=====";
