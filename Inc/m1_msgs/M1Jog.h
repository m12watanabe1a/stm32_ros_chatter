#ifndef _ROS_m1_msgs_M1Jog_h
#define _ROS_m1_msgs_M1Jog_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace m1_msgs
{

  class M1Jog : public ros::Msg
  {
    public:
      typedef uint8_t _isJoint_type;
      _isJoint_type isJoint;
      typedef uint8_t _jogCmd_type;
      _jogCmd_type jogCmd;
      typedef float _vel_type;
      _vel_type vel;
      typedef float _acc_type;
      _acc_type acc;

    M1Jog():
      isJoint(0),
      jogCmd(0),
      vel(0),
      acc(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->isJoint >> (8 * 0)) & 0xFF;
      offset += sizeof(this->isJoint);
      *(outbuffer + offset + 0) = (this->jogCmd >> (8 * 0)) & 0xFF;
      offset += sizeof(this->jogCmd);
      union {
        float real;
        uint32_t base;
      } u_vel;
      u_vel.real = this->vel;
      *(outbuffer + offset + 0) = (u_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vel);
      union {
        float real;
        uint32_t base;
      } u_acc;
      u_acc.real = this->acc;
      *(outbuffer + offset + 0) = (u_acc.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acc.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_acc.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_acc.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->acc);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->isJoint =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->isJoint);
      this->jogCmd =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->jogCmd);
      union {
        float real;
        uint32_t base;
      } u_vel;
      u_vel.base = 0;
      u_vel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vel = u_vel.real;
      offset += sizeof(this->vel);
      union {
        float real;
        uint32_t base;
      } u_acc;
      u_acc.base = 0;
      u_acc.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acc.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_acc.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_acc.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->acc = u_acc.real;
      offset += sizeof(this->acc);
     return offset;
    }

    const char * getType(){ return "m1_msgs/M1Jog"; };
    const char * getMD5(){ return "ecb7bc260fda5a5714376dcbe3d6847a"; };

  };

}
#endif
