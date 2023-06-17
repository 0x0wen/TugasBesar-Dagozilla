#ifndef _ROS_control_HardwareCommand_h
#define _ROS_control_HardwareCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace control
{

  class HardwareCommand : public ros::Msg
  {
    public:
      typedef float _motor1_type;
      _motor1_type motor1;
      typedef float _motor2_type;
      _motor2_type motor2;
      typedef float _motor3_type;
      _motor3_type motor3;
      typedef float _motor4_type;
      _motor4_type motor4;

    HardwareCommand():
      motor1(0),
      motor2(0),
      motor3(0),
      motor4(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_motor1;
      u_motor1.real = this->motor1;
      *(outbuffer + offset + 0) = (u_motor1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motor1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motor1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor1);
      union {
        float real;
        uint32_t base;
      } u_motor2;
      u_motor2.real = this->motor2;
      *(outbuffer + offset + 0) = (u_motor2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motor2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motor2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor2);
      union {
        float real;
        uint32_t base;
      } u_motor3;
      u_motor3.real = this->motor3;
      *(outbuffer + offset + 0) = (u_motor3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motor3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motor3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor3);
      union {
        float real;
        uint32_t base;
      } u_motor4;
      u_motor4.real = this->motor4;
      *(outbuffer + offset + 0) = (u_motor4.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor4.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motor4.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motor4.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor4);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_motor1;
      u_motor1.base = 0;
      u_motor1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_motor1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_motor1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->motor1 = u_motor1.real;
      offset += sizeof(this->motor1);
      union {
        float real;
        uint32_t base;
      } u_motor2;
      u_motor2.base = 0;
      u_motor2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_motor2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_motor2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->motor2 = u_motor2.real;
      offset += sizeof(this->motor2);
      union {
        float real;
        uint32_t base;
      } u_motor3;
      u_motor3.base = 0;
      u_motor3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_motor3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_motor3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->motor3 = u_motor3.real;
      offset += sizeof(this->motor3);
      union {
        float real;
        uint32_t base;
      } u_motor4;
      u_motor4.base = 0;
      u_motor4.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor4.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_motor4.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_motor4.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->motor4 = u_motor4.real;
      offset += sizeof(this->motor4);
     return offset;
    }

    virtual const char * getType() override { return "control/HardwareCommand"; };
    virtual const char * getMD5() override { return "7870b959b33d58fdf72aa92aca4c8520"; };

  };

}
#endif
