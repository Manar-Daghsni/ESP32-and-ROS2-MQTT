# ROS2 Nodes

## mqtt_bridge.py
- Location: `robot_call/mqtt_bridge.py`
- Function: Subscribes to MQTT messages from ESP32 and republishes as ROS2 topics
- Subscribes: MQTT topics from ESP32
- Publishes: `/esp32/button_events`

## call_manager.py
- Location: `robot_call/call_manager.py`
- Function: Handles incoming ROS2 messages and triggers robot actions
- Subscribes: `/esp32/button_events`
- Publishes: ROS2 actions 
