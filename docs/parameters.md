# Node Parameters

## mqtt_bridge.py
- `mqtt_broker_ip`: IP of MQTT broker (default: `192.168.1.100`)
- `mqtt_broker_port`: Broker port (default: `1883`)
- `mqtt_topic`: Topic ESP32 publishes to (default: `esp32/button`)
- `ros2_topic`: ROS2 topic to publish messages to (default: `/esp32/button_events`)

## call_manager.py
- `action_mode`: Mode of robot action triggered (default: `simple_call`)
