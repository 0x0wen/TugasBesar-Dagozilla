#ifndef _ROS_control_EncoderData_h
#define _ROS_control_EncoderData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace control
{

  class EncoderData : public ros::Msg
  {
    public:
      typedef float _en_ext1_type;
      _en_ext1_type en_ext1;
      typedef float _en_ext2_type;
      _en_ext2_type en_ext2;
      typedef float _en_ext3_type;
      _en_ext3_type en_ext3;
      typedef float _en_in1_type;
      _en_in1_type en_in1;
      typedef float _en_in2_type;
      _en_in2_type en_in2;
      typedef float _en_in3_type;
      _en_in3_type en_in3;
      typedef float _en_in4_type;
      _en_in4_type en_in4;

    EncoderData():
      en_ext1(0),
      en_ext2(0),
      en_ext3(0),
      en_in1(0),
      en_in2(0),
      en_in3(0),
      en_in4(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_en_ext1;
      u_en_ext1.real = this->en_ext1;
      *(outbuffer + offset + 0) = (u_en_ext1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_en_ext1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_en_ext1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_en_ext1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->en_ext1);
      union {
        float real;
        uint32_t base;
      } u_en_ext2;
      u_en_ext2.real = this->en_ext2;
      *(outbuffer + offset + 0) = (u_en_ext2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_en_ext2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_en_ext2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_en_ext2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->en_ext2);
      union {
        float real;
        uint32_t base;
      } u_en_ext3;
      u_en_ext3.real = this->en_ext3;
      *(outbuffer + offset + 0) = (u_en_ext3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_en_ext3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_en_ext3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_en_ext3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->en_ext3);
      union {
        float real;
        uint32_t base;
      } u_en_in1;
      u_en_in1.real = this->en_in1;
      *(outbuffer + offset + 0) = (u_en_in1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_en_in1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_en_in1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_en_in1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->en_in1);
      union {
        float real;
        uint32_t base;
      } u_en_in2;
      u_en_in2.real = this->en_in2;
      *(outbuffer + offset + 0) = (u_en_in2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_en_in2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_en_in2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_en_in2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->en_in2);
      union {
        float real;
        uint32_t base;
      } u_en_in3;
      u_en_in3.real = this->en_in3;
      *(outbuffer + offset + 0) = (u_en_in3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_en_in3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_en_in3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_en_in3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->en_in3);
      union {
        float real;
        uint32_t base;
      } u_en_in4;
      u_en_in4.real = this->en_in4;
      *(outbuffer + offset + 0) = (u_en_in4.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_en_in4.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_en_in4.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_en_in4.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->en_in4);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_en_ext1;
      u_en_ext1.base = 0;
      u_en_ext1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_en_ext1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_en_ext1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_en_ext1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->en_ext1 = u_en_ext1.real;
      offset += sizeof(this->en_ext1);
      union {
        float real;
        uint32_t base;
      } u_en_ext2;
      u_en_ext2.base = 0;
      u_en_ext2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_en_ext2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_en_ext2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_en_ext2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->en_ext2 = u_en_ext2.real;
      offset += sizeof(this->en_ext2);
      union {
        float real;
        uint32_t base;
      } u_en_ext3;
      u_en_ext3.base = 0;
      u_en_ext3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_en_ext3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_en_ext3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_en_ext3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->en_ext3 = u_en_ext3.real;
      offset += sizeof(this->en_ext3);
      union {
        float real;
        uint32_t base;
      } u_en_in1;
      u_en_in1.base = 0;
      u_en_in1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_en_in1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_en_in1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_en_in1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->en_in1 = u_en_in1.real;
      offset += sizeof(this->en_in1);
      union {
        float real;
        uint32_t base;
      } u_en_in2;
      u_en_in2.base = 0;
      u_en_in2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_en_in2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_en_in2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_en_in2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->en_in2 = u_en_in2.real;
      offset += sizeof(this->en_in2);
      union {
        float real;
        uint32_t base;
      } u_en_in3;
      u_en_in3.base = 0;
      u_en_in3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_en_in3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_en_in3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_en_in3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->en_in3 = u_en_in3.real;
      offset += sizeof(this->en_in3);
      union {
        float real;
        uint32_t base;
      } u_en_in4;
      u_en_in4.base = 0;
      u_en_in4.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_en_in4.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_en_in4.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_en_in4.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->en_in4 = u_en_in4.real;
      offset += sizeof(this->en_in4);
     return offset;
    }

    virtual const char * getType() override { return "control/EncoderData"; };
    virtual const char * getMD5() override { return "23ea1aec3b3aed5da94835b8bde1468c"; };

  };

}
#endif
