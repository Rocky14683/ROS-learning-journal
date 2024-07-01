// Auto-generated. Do not edit!

// (in-package learn_topic.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Information {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.company = null;
      this.year = null;
    }
    else {
      if (initObj.hasOwnProperty('company')) {
        this.company = initObj.company
      }
      else {
        this.company = '';
      }
      if (initObj.hasOwnProperty('year')) {
        this.year = initObj.year
      }
      else {
        this.year = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Information
    // Serialize message field [company]
    bufferOffset = _serializer.string(obj.company, buffer, bufferOffset);
    // Serialize message field [year]
    bufferOffset = _serializer.string(obj.year, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Information
    let len;
    let data = new Information(null);
    // Deserialize message field [company]
    data.company = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [year]
    data.year = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.company);
    length += _getByteLength(object.year);
    return length + 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'learn_topic/Information';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4092f70730c2545e71ae30dda7615194';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string company
    string year
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Information(null);
    if (msg.company !== undefined) {
      resolved.company = msg.company;
    }
    else {
      resolved.company = ''
    }

    if (msg.year !== undefined) {
      resolved.year = msg.year;
    }
    else {
      resolved.year = ''
    }

    return resolved;
    }
};

module.exports = Information;
