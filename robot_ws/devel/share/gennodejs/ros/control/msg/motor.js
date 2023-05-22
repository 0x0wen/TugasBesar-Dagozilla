// Auto-generated. Do not edit!

// (in-package control.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class motor {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.motor1 = null;
      this.motor2 = null;
      this.motor3 = null;
      this.motor4 = null;
    }
    else {
      if (initObj.hasOwnProperty('motor1')) {
        this.motor1 = initObj.motor1
      }
      else {
        this.motor1 = 0.0;
      }
      if (initObj.hasOwnProperty('motor2')) {
        this.motor2 = initObj.motor2
      }
      else {
        this.motor2 = 0.0;
      }
      if (initObj.hasOwnProperty('motor3')) {
        this.motor3 = initObj.motor3
      }
      else {
        this.motor3 = 0.0;
      }
      if (initObj.hasOwnProperty('motor4')) {
        this.motor4 = initObj.motor4
      }
      else {
        this.motor4 = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type motor
    // Serialize message field [motor1]
    bufferOffset = _serializer.float32(obj.motor1, buffer, bufferOffset);
    // Serialize message field [motor2]
    bufferOffset = _serializer.float32(obj.motor2, buffer, bufferOffset);
    // Serialize message field [motor3]
    bufferOffset = _serializer.float32(obj.motor3, buffer, bufferOffset);
    // Serialize message field [motor4]
    bufferOffset = _serializer.float32(obj.motor4, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type motor
    let len;
    let data = new motor(null);
    // Deserialize message field [motor1]
    data.motor1 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [motor2]
    data.motor2 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [motor3]
    data.motor3 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [motor4]
    data.motor4 = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'control/motor';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '7870b959b33d58fdf72aa92aca4c8520';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 motor1
    float32 motor2
    float32 motor3
    float32 motor4
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new motor(null);
    if (msg.motor1 !== undefined) {
      resolved.motor1 = msg.motor1;
    }
    else {
      resolved.motor1 = 0.0
    }

    if (msg.motor2 !== undefined) {
      resolved.motor2 = msg.motor2;
    }
    else {
      resolved.motor2 = 0.0
    }

    if (msg.motor3 !== undefined) {
      resolved.motor3 = msg.motor3;
    }
    else {
      resolved.motor3 = 0.0
    }

    if (msg.motor4 !== undefined) {
      resolved.motor4 = msg.motor4;
    }
    else {
      resolved.motor4 = 0.0
    }

    return resolved;
    }
};

module.exports = motor;
