# High Level Test Plan:
|Test Id|Description|Expected input|Expected output|Actual output|pass/fail|
|-------|-----------|--------------|---------------|-------------|---------|
|H1 | car window status |Blue switch is pressed once |Shall Print window status |Shall Print window status|pass|
|H2 | car Alarm status |Blue switch is pressed twice|Shall Print alarm status |Shall Print alarm status|pass|
|H3 | car Battery status |Blue switch is pressed thrice|Shall Print battery status |Shall Print battery status|pass|
|H4 | car door status |Blue switch is pressed four times|Shall Print door status |Shall Print door status|pass|

# Low level Test plan:
|Test Id|Description|Expected input|Expected output|Actual output|pass/fail|
|-------|-----------|--------------|---------------|-------------|---------|
|H1 | car window status |Blue switch is pressed once |all led's must be ON |all led's must be ON|pass|
|H2 | car Alarm status |Blue switch is pressed twice|all led's must be OFF|all led's must be OFF|pass|
|H3 | car Battery status |Blue switch is pressed thrice|all led's must be ON in clk wise|all led's must be ON in clk wise|pass|
|H4 | car door status |Blue switch is pressed four times|all led's must be ON in anti-clk wise|all led's must be ON in anti-clk wise|pass|
|H5 | button press count check |count the button press |one/two/three/four |one/two/three/four |pass|

