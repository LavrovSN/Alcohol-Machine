const char indexHTML[] PROGMEM = R"=====(
 <!DOCTYPE html>
 <html>
 <style>
 	.col1{
 		width: 30%;
 	}
 	.col2 {
 		width: 30%;
 		text-align: right;
 	}
 	.col3 {
 		width: 8%;
 		text-align: right;
 	}
 	.col3l {
 		width: 8%;
 		text-align: left;
 	}
 	.col3c {
 		width: 8%;
 		text-align: center;
 	}
 	.bordertext{
 		border: 1px solid black;
 		padding: 0 10px;
 		text-align: center;
 	}
 	.titletext{
 		font-size: 250%;
 		font-family: "Times New Roman", Times, serif;
 		text-align: center;
 		font-weight: bold;
 	}
 	.checkAndRadio {
 		margin-left: 0;
 	}
 </style>
 <head>
 	<meta charset="utf-8">
 	<title>Alcohol Machine v0.1</title>
 	<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css'>
 </head>
 <body>
 <table width="60%" cellpadding="5" cellspacing="0" border="0" cellpadding="2" cellspacing="2" class="table table-bordered table-striped">
     <tr>
       <td colspan="3" class="col1">
         <div class=titletext>
           Текущее состояние
         </div>
       </td>
     </tr>
     <tr>
       <td id="status" align="center">Ожидание</td>
     </tr>
 </table>
 <table class="table table-bordered table-striped">
     <tr>
       <td colspan="3" class="col1" >
         <div class="titletext">Показания датчиков</div>
       </td>
     </tr>
     <tr>
       <td class="col1">Температура паров в перегонном кубе</td>
       <td id="tSensor1" colspan="2" class="col2"></td>
     </tr>
     <tr>
       <td class="col1">Температура паров в блоке МСД</td>
       <td id="tSensor2" colspan="2" class="col2"></td>
     </tr>
     <tr>
       <td class="col1">Состояние основного нагревательного элемента</td>
       <td id="mainPower" colspan="2" class="col2"></td>
     </tr>
     <tr>
       <td class="col1">Состояние дополнительного нагревательного элемента</td>
       <td id="addPower" colspan="2" class="col2"></td>
     </tr>
     <tr>
       <td class="col1">Клапан отбора первой фракции</td>
       <td id="valve1" colspan="2" class="col2"></td>
     </tr>
     <tr>
       <td class="col1">Клапан отбора второй фракции</td>
       <td id="valve2" colspan="2" class="col2"></td>
     </tr>
     <tr>
       <td class="col1">Клапан отбора третьей фракции</td>
       <td id="valve3" colspan="2" class="col2"></td>
     </tr>
     <tr>
       <td class="col1">Клапан обхода МСД</td>
       <td id="valve4" colspan="2" class="col2"></td>
     </tr>
     <tr>
       <td class="col1">Наличие жидкости в перегонном кубе</td>
       <td id="inputLiquidLevel" colspan="2" class="col2"></td>
     </tr>
     <tr>
       <td class="col1">Уровень жидкости в приемной колбе первой фракции</td>
       <td id="outputLiquidLevel1" colspan="2" class="col2"></td>
     </tr>
     <tr>
       <td class="col1">Уровень жидкости в приемной колбе второй фракции</td>
       <td id="outputLiquidLevel2" colspan="2" class="col2"></td>
     </tr>
     <tr>
       <td class="col1">Уровень жидкости в приемной колбе третьей фракции</td>
       <td id="outputLiquidLevel3" colspan="2" class="col2"></td>
     </tr>
      <tr>
       <td class="col1">Влажность воздуха</td>
       <td id="airHumidity" colspan="2" class="col2"></td>
     </tr>
     <tr>
       <td class="col1">Задымленность</td>
       <td id="smokeLevel" colspan="2" class="col2"></td>
     </tr>
     </table>
     <table class="table table-bordered table-striped">
 	    <tr>
 	      <td colspan="2"><div class="titletext">Управление</div></td>
 	      </tr>
 	      <tr>
 	      <td class="col3c">
 	      	<button id="start" class="btn btn-success btn-lg">Старт</button>
 	      </td>
 	      <td class="col3c">
 	      	<button id="stahp" class="btn btn-danger btn-lg">Стоп</button>
 	      </td>
 	    </tr>
     </table>
     <table class="table table-bordered table-striped">
      <tr>
       <td colspan="6"><div class="titletext">Настройка состояний</div></td>
     </tr>
 	<tr>
       <td class="col1" rowspan="2"><strong>Показания датчика</strong></td>
       <td class="col3c" colspan="5"><strong>Параметры для состояния:</strong></td>
       </tr>
       <tr>
       <td class="col3l">Разогрев</td>
       <td class="col3l">Отбор первой фракции</td>
       <td class="col3l">Отбор второй фракции</td>
       <td class="col3l">Отбор третьей фракции</td>
       <td class="col3l">Авария</td>
     </tr>
     <tr>
       <td class="col1">Температура паров в перегонном кубе</td>
       <td class="col3l">
      		<div class="form-group">
       			<label for="heatingTemp1Min" class="col-sm-2 control-label">От: </label>
       			<div class="col-sm-9">
       				<input id="heatingTemp1Min" type="number" min="0" max="150" class="form-control">
       			</div>
       		</div>
       		<div class="form-group">
       			<label for="heatingTheatingTemp1Maxemp1Min" class="col-sm-2 control-label">До: </label>
       			<div class="col-sm-9">
       				<input id="heatingTemp1Max" type="number" min="0" max="150" class="form-control">
   				</div>
   			</div>
       </td>
       <td class="col3l">

      		<div class="form-group">
       			<label for="onFirstTemp1Min" class="col-sm-2 control-label">От: </label>
       			<div class="col-sm-9">
       				<input id="onFirstTemp1Min" type="number" min="0" max="150" class="form-control">
       			</div>
       		</div>
       		<div class="form-group">
       			<label for="onFirstTemp1Max" class="col-sm-2 control-label">До: </label>
       			<div class="col-sm-9">
       				<input id="onFirstTemp1Max" type="number" min="0" max="150" class="form-control">
   				</div>
   			</div>
       </td>
       <td class="col3l">
      		<div class="form-group">
       			<label for="onSecondTemp1Min" class="col-sm-2 control-label">От: </label>
       			<div class="col-sm-9">
       				<input id="onSecondTemp1Min" type="number" min="0" max="150" class="form-control">
       			</div>
       		</div>
       		<div class="form-group">
       			<label for="onSecondTemp1Max" class="col-sm-2 control-label">До: </label>
       			<div class="col-sm-9">
       				<input id="onSecondTemp1Max" type="number" min="0" max="150" class="form-control">
   				</div>
   			</div>
       </td>
       <td class="col3l">
      		<div class="form-group">
       			<label for="onThirdTemp1Min" class="col-sm-2 control-label">От: </label>
       			<div class="col-sm-9">
       				<input id="onThirdTemp1Min" type="number" min="0" max="150" class="form-control">
       			</div>
       		</div>
       		<div class="form-group">
       			<label for="onThirdTemp1Max" class="col-sm-2 control-label">До: </label>
       			<div class="col-sm-9">
       				<input id="onThirdTemp1Max" type="number" min="0" max="150" class="form-control">
   				</div>
   			</div>
       </td>
       <td class="col3l">

      		<div class="form-group">
       			<label for="crashTemp1Min" class="col-sm-2 control-label">От: </label>
       			<div class="col-sm-9">
       				<input id="crashTemp1Min" type="number" min="0" max="150" class="form-control">
       			</div>
       		</div>
       		<div class="form-group">
       			<label for="crashTemp1Max" class="col-sm-2 control-label">До: </label>
       			<div class="col-sm-9">
       				<input id="crashTemp1Max" type="number" min="0" max="150" class="form-control">
   				</div>
   			</div>
       </td>
     </tr>
     <tr>
       <td class="col1">Температура паров в блоке МСД</td>
       <td class="col3l">

      		<div class="form-group">
       			<label for="heatingTemp2Min" class="col-sm-2 control-label">От: </label>
       			<div class="col-sm-9">
       				<input id="heatingTemp2Min" type="number" min="0" max="150" class="form-control">
       			</div>
       		</div>
       		<div class="form-group">
       			<label for="heatingTemp2Max" class="col-sm-2 control-label">До: </label>
       			<div class="col-sm-9">
       				<input id="heatingTemp2Max" type="number" min="0" max="150" class="form-control">
   				</div>
   			</div>
       </td>
       <td class="col3l">

      		<div class="form-group">
       			<label for="onFirstTemp2Min" class="col-sm-2 control-label">От: </label>
       			<div class="col-sm-9">
       				<input id="onFirstTemp2Min" type="number" min="0" max="150" class="form-control">
       			</div>
       		</div>
       		<div class="form-group">
       			<label for="onFirstTemp2Max" class="col-sm-2 control-label">До: </label>
       			<div class="col-sm-9">
       				<input id="onFirstTemp2Max" type="number" min="0" max="150" class="form-control">
   				</div>
   			</div>
       </td>
       <td class="col3l">

      		<div class="form-group">
       			<label for="onSecondTemp2Min" class="col-sm-2 control-label">От: </label>
       			<div class="col-sm-9">
       				<input id="onSecondTemp2Min" type="number" min="0" max="150" class="form-control">
       			</div>
       		</div>
       		<div class="form-group">
       			<label for="onSecondTemp2Max" class="col-sm-2 control-label">До: </label>
       			<div class="col-sm-9">
       				<input id="onSecondTemp2Max" type="number" min="0" max="150" class="form-control">
   				</div>
   			</div>
       </td>
       <td class="col3l">

      		<div class="form-group">
       			<label for="onThirdTemp2Min" class="col-sm-2 control-label">От: </label>
       			<div class="col-sm-9">
       				<input id="onThirdTemp2Min" type="number" min="0" max="150" class="form-control">
       			</div>
       		</div>
       		<div class="form-group">
       			<label for="onThirdTemp2Max" class="col-sm-2 control-label">До: </label>
       			<div class="col-sm-9">
       				<input id="onThirdTemp2Max" type="number" min="0" max="150" class="form-control">
   				</div>
   			</div>
       </td>
       <td class="col3l">

      		<div class="form-group">
       			<label for="crashTemp2Min" class="col-sm-2 control-label">От: </label>
       			<div class="col-sm-9">
       				<input id="crashTemp2Min" type="number" min="0" max="150" class="form-control" required>
       			</div>
       		</div>
       		<div class="form-group">
       			<label for="crashTemp2Max" class="col-sm-2 control-label">До: </label>
       			<div class="col-sm-9">
       				<input id="crashTemp2Max" type="number" min="0" max="150" class="form-control" required>
   				</div>
   			</div>
       </td>
     </tr>
     <tr>
       <td class="col1">Состояние основного нагревательного элемента</td>
       <td class="col3l">
       	<div class="radio">
   			<label>
     			<input type="radio" name="heatingMainPower" id="heatingMainPowerOn" value="on">
     			<strong>Вкл.</strong>
   			</label>
 		</div>
 		<div class="radio">
   			<label>
     			<input type="radio" name="heatingMainPower" id="heatingMainPowerOff" value="off">
     			<strong>Выкл.</strong>
   			</label>
 		</div>
       </td>
       <td class="col3l">
       	<div class="radio">
   			<label>
     			<input type="radio" name="onFirstMainPower" id="onFirstMainPowerOn" value="on">
     			<strong>Вкл.</strong>
   			</label>
 		</div>
 		<div class="radio">
   			<label>
     			<input type="radio" name="onFirstMainPower" id="onFirstMainPowerOff" value="off">
     			<strong>Выкл.</strong>
   			</label>
 		</div>
       </td>
       <td class="col3l">
       	<div class="radio">
   			<label>
     			<input type="radio" name="onSecondMainPower" id="onSecondMainPowerOn" value="on">
     			<strong>Вкл.</strong>
   			</label>
 		</div>
 		<div class="radio">
   			<label>
     			<input type="radio" name="onSecondMainPower" id="onSecondMainPowerOff" value="off">
     			<strong>Выкл.</strong>
   			</label>
 		</div>
       </td>
       <td class="col3l">
       	<div class="radio">
   			<label>
     			<input type="radio" name="onThirdMainPower" id="onThirdMainPowerOn" value="on">
     			<strong>Вкл.</strong>
   			</label>
 		</div>
 		<div class="radio">
   			<label>
     			<input type="radio" name="onThirdMainPower" id="onThirdMainPowerOff" value="off">
     			<strong>Выкл.</strong>
   			</label>
 		</div>
       </td>
     </tr>
     <tr>
       <td class="col1">Состояние дополнительного нагревательного элемента</td>
       <td class="col3l">
       	<div class="radio">
   			<label>
     			<input type="radio" name="heatingAddPower" id="heatingAddPowerOn" value="on">
     			<strong>Вкл.</strong>
   			</label>
 		</div>
 		<div class="radio">
   			<label>
     			<input type="radio" name="heatingAddPower" id="heatingAddPowerOff" value="off">
     			<strong>Выкл.</strong>
   			</label>
 		</div>
       </td>
       <td class="col3l">
       	<div class="radio">
   			<label>
     			<input type="radio" name="onFirstAddPower" id="onFirstAddPowerOn" value="on">
     			<strong>Вкл.</strong>
   			</label>
 		</div>
 		<div class="radio">
   			<label>
     			<input type="radio" name="onFirstAddPower" id="onFirstAddPowerOff" value="off">
     			<strong>Выкл.</strong>
   			</label>
 		</div>
       </td>
       <td class="col3l">
       	<div class="radio">
   			<label>
     			<input type="radio" name="onSecondAddPower" id="onSecondAddPowerOn" value="on">
     			<strong>Вкл.</strong>
   			</label>
 		</div>
 		<div class="radio">
   			<label>
     			<input type="radio" name="onSecondAddPower" id="onSecondAddPowerOff" value="off">
     			<strong>Выкл.</strong>
   			</label>
 		</div>
       </td>
       <td class="col3l">
       	<div class="radio">
   			<label>
     			<input type="radio" name="onThirdAddPower" id="onThirdAddPowerOn" value="on">
     			<strong>Вкл.</strong>
   			</label>
 		</div>
 		<div class="radio">
   			<label>
     			<input type="radio" name="onThirdAddPower" id="onThirdAddPowerOff" value="off">
     			<strong>Выкл.</strong>
   			</label>
 		</div>
       </td>
     </tr>
     <tr>
       <td colspan="6" class="col1">
           <p style="text-align: center">
             <button id="ok" class="btn btn-primary btn-lg">Принять</button>
           </p>
       </td>
     </tr>
 </table>
 <script src="setSensorsData.js" defer></script>
 <script src="click.js" defer></script>
 <script src="setParams.js" defer></script>
 <script src="app.js" defer></script>
 </body>
 </html>

)=====";
