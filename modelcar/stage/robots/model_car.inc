define laser ranger
(
  sensor
  (
    range [0 32.5]
    fov 58.0
    samples 360
  )
  # generic model properties
  color "green"
  size [ 0.2 0.2 0.3 ]
)

#
# Robot model:
# footprint (counter-clockwise): [-0.1,-0.125], [0.5,-0.125], [0.5,0.125], [-0.1,0.125]
# center of rotation: [0,0]
# wheelbase: 0.4

define carlike_robot position
(
  pose [ 0.0 0.0 0.0 0.0 ]

  odom_error [0.03 0.03 999999 999999 999999 0.02]

  size [ 0.37 0.19 0.14 ] # this models the footprint (rectangular), but shifted such that the bottom-left corner is in [0,0]. The center of rotation now here at [0.37/2,0.19/2,0.14/2]

  # correct center of rotation:
  origin [ 0.3 0.1 0.0 0.0]
  gui_nose 1
  color "red"

  # kinematics
  drive "car"
  wheelbase 0.27 # distance between both axles 27
  
  # spawn sensors
  laser(pose [ -0.03 0.0 0.03 0.0 ])
)

define carlike_robot2 position
(
  pose [ 0.0 0.0 0.0 0.0 ]
  size [ 0.37 0.19 0.14 ]
  # correct center of rotation: set it to /base_link (but ignore height)
  #origin [ 0.185 0.095 0.0 0.0]
  gui_nose 1
  color "red"

  # kinematics
  drive "car"
  wheelbase 0.27 # distance between both axles
  velocity_bounds [-3 10 -0 0 -0 0 -45 45 ]          
  acceleration_bounds [-3 3 -0 0 -0 0 -10 10]

  # localization
  localization "gps" # "gps" or "odom"
  localization_origin [ 0.0 0.0 0.0 0.0 ]
  odom_error [0.03 0.03 0.03 0.02]
  
  # spawn sensors
  laser(pose [ -0.03 0.0 0.03 0.0 ])
)
