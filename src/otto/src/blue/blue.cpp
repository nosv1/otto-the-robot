#include <chrono>
#include <memory>
#include <string>

#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

class Blue : public rclcpp::Node {
 public:
  Blue() : Node("blue"), count_(0) {
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
    subscription_ = this->create_subscription<nav_msgs::msg::Odometry>(
        "odom", 10, std::bind(&Blue::subscriber_callback, this, std::placeholders::_1));
    timer_ = this->create_wall_timer(500ms, std::bind(&Blue::publisher_callback, this));
  }

 private:
  void publisher_callback() {
    auto twist_msg = geometry_msgs::msg::Twist();
    twist_msg.linear.x = 0.5;
    twist_msg.linear.y = 0.0;
    twist_msg.linear.z = 0.0;

    twist_msg.angular.x = 0.0;
    twist_msg.angular.y = 0.0;
    twist_msg.angular.z = 0.2;
    this->publisher_->publish(twist_msg);
    RCLCPP_INFO(this->get_logger(), "Publishing Twist: linear.x=%.2f angular.z=%.2f",
                twist_msg.linear.x, twist_msg.angular.z);
  };

  void subscriber_callback(const nav_msgs::msg::Odometry::SharedPtr msg) {
    RCLCPP_INFO(this->get_logger(), "Read Odom: '[%.2f, %.2f, %.2f]'", msg->pose.pose.position.x,
                msg->pose.pose.position.y, msg->pose.pose.position.z);
  }

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr subscription_;
  size_t count_;
};

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Blue>());
  rclcpp::shutdown();
  return 0;
}