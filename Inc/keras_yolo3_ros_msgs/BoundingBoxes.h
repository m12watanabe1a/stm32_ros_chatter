#ifndef _ROS_keras_yolo3_ros_msgs_BoundingBoxes_h
#define _ROS_keras_yolo3_ros_msgs_BoundingBoxes_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "keras_yolo3_ros_msgs/BoundingBox.h"

namespace keras_yolo3_ros_msgs
{

  class BoundingBoxes : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef std_msgs::Header _image_header_type;
      _image_header_type image_header;
      uint32_t bounding_boxes_length;
      typedef keras_yolo3_ros_msgs::BoundingBox _bounding_boxes_type;
      _bounding_boxes_type st_bounding_boxes;
      _bounding_boxes_type * bounding_boxes;

    BoundingBoxes():
      header(),
      image_header(),
      bounding_boxes_length(0), bounding_boxes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->image_header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->bounding_boxes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->bounding_boxes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->bounding_boxes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->bounding_boxes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bounding_boxes_length);
      for( uint32_t i = 0; i < bounding_boxes_length; i++){
      offset += this->bounding_boxes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->image_header.deserialize(inbuffer + offset);
      uint32_t bounding_boxes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      bounding_boxes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      bounding_boxes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      bounding_boxes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->bounding_boxes_length);
      if(bounding_boxes_lengthT > bounding_boxes_length)
        this->bounding_boxes = (keras_yolo3_ros_msgs::BoundingBox*)realloc(this->bounding_boxes, bounding_boxes_lengthT * sizeof(keras_yolo3_ros_msgs::BoundingBox));
      bounding_boxes_length = bounding_boxes_lengthT;
      for( uint32_t i = 0; i < bounding_boxes_length; i++){
      offset += this->st_bounding_boxes.deserialize(inbuffer + offset);
        memcpy( &(this->bounding_boxes[i]), &(this->st_bounding_boxes), sizeof(keras_yolo3_ros_msgs::BoundingBox));
      }
     return offset;
    }

    const char * getType(){ return "keras_yolo3_ros_msgs/BoundingBoxes"; };
    const char * getMD5(){ return "004f6f4f48a741582d10735997905846"; };

  };

}
#endif
