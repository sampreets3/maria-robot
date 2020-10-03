EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 2365 1325 0    50   Input ~ 0
NCS
Text HLabel 2365 1400 0    50   Input ~ 0
MOSI
Text HLabel 2365 1480 0    50   Input ~ 0
MISO
Text HLabel 2365 1550 0    50   Input ~ 0
SCK
$Comp
L Driver_Motor:DRV8833PWP U?
U 1 1 5F41D7C4
P 4550 3275
F 0 "U?" H 4550 4156 50  0000 C CNN
F 1 "DRV8833PWP" H 4550 4065 50  0000 C CNN
F 2 "Package_SO:HTSSOP-16-1EP_4.4x5mm_P0.65mm_EP3.4x5mm_Mask2.46x2.31mm_ThermalVias" H 5000 3725 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/drv8833.pdf" H 4400 3825 50  0001 C CNN
	1    4550 3275
	1    0    0    -1  
$EndComp
Text HLabel 4410 4095 0    50   Input ~ 0
GND
$Comp
L power:GND #PWR?
U 1 1 5F42D256
P 4505 4145
F 0 "#PWR?" H 4505 3895 50  0001 C CNN
F 1 "GND" H 4510 3972 50  0000 C CNN
F 2 "" H 4505 4145 50  0001 C CNN
F 3 "" H 4505 4145 50  0001 C CNN
	1    4505 4145
	1    0    0    -1  
$EndComp
Wire Wire Line
	4505 4095 4450 4095
Wire Wire Line
	4505 4095 4505 4145
Wire Wire Line
	4450 4095 4450 3975
Connection ~ 4450 4095
Wire Wire Line
	4450 4095 4410 4095
Wire Wire Line
	4550 3975 4550 4095
Wire Wire Line
	4550 4095 4505 4095
Connection ~ 4505 4095
Text HLabel 5255 3375 2    50   Output ~ 0
M1A
Text HLabel 5250 3475 2    50   Output ~ 0
M1B
Wire Wire Line
	5250 3475 5150 3475
Wire Wire Line
	5150 3375 5255 3375
Text HLabel 5250 3575 2    50   Output ~ 0
M2A
Text HLabel 5245 3675 2    50   Output ~ 0
M2B
Wire Wire Line
	5245 3675 5150 3675
$EndSCHEMATC
