

1:
	pandoc --latex-engine=xelatex   \
					-V papersize:a4paper    \
					--template=./LaTeX_ES.latex    \
					-o  Robotica_avanzada.docx  \
					Cabecera.md        \
					Cabecera_latex.md \
					0.0.Indice.md \
					1.0.Introducción.md \
					1.1.DondeComprar.md \
					1.2.QueComprar.md \
					1.3.opensource.md \
					2.0.Hardware.md \
					2.1.Simuladores.md \
					2.2.GuiaRapida.md \
					3.0.ProgramacionArduino.md \
					3.1.ArduinoBlocks.md \
					3.2.Bitbloq.md \
					3.3.mBlock.md \
					3.4.OtrosEntornosBloques.md \
					3.5.ArduinoIDE.md \
					3.6.Programacion_C++.md \
					3.7.ManejandoPotencia.md \
					4.1.sensores.md \
					4.2.ProyectosSencillosConSensores.md \
					4.3.Echidna.md \
					5.0.Motores.md \
					6.0.Comunicaciones.md \
					6.1.Serie.md \
					6.2.Bluetooth.md \
					6.3.Infrarrojos.md \
					6.4.Wifi-esp8266.md \
					7.1.MasAllaArduino.md \
					7.3.Microbit.md \
					8.1.proyectoHacer.md \
					8.2.proyectos.md \
					8.4.escornabot.md
