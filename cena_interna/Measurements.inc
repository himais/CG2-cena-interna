//////////////////////////////////////////////////////////////////////////
// Measurements.inc  1.0  KEA  Copyright(c) 2005, K.E. Ayers Designs  	//
//////////////////////////////////////////////////////////////////////////
// Defines the dimensions for the house's walls, doors and windows.     //
//////////////////////////////////////////////////////////////////////////

#ifndef (_Measurements_inc_)
#declare _Measurements_inc_ = true;

#ifdef (_TRACE_INCLUDES_)
    #debug "Measurements.inc\n"
#end


//////////////////////////////////////////////////////////////////////////
// Global values.

#declare WALL_HEIGHT            = AS_INCHES(9, 0);
#declare WALL_THICKNESS         = 3.5 * INCH;
#declare FLOOR_THICKNESS        = 1/2 * INCH;

#declare CEILING_HEIGHT         = WALL_HEIGHT;

#declare DOOR_HEIGHT            = AS_INCHES(6, 9);
#declare DOOR_THICKNESS         = 1.5 * INCH;

#declare WINDOW_HEIGHT          = 54.5 * INCH;                  // Most windows.
#declare WINDOW_BOTTOM          = DOOR_HEIGHT - WINDOW_HEIGHT;  // Most windows.

#declare TRIM_THICKNESS         = 1/2 * INCH;
#declare BASEBOARD_WIDTH        = 4.5 * INCH;
#declare CROWN_MOLDING_WIDTH    = 4.5 * INCH;
#declare FRAME_TRIM_WIDTH       = 3.5 * INCH;


//////////////////////////////////////////////////////////////////////////
// Room and wall dimensions.

#declare KITCHEN_W_CAB_LENGTH   = 36 * INCH         // Corner lazy susan
                                    + 30 * INCH     // Stove
                                    + 9 * INCH      // Skinny, single-door
                                    + 24 * INCH     // Dishwasher
                                    + 15 * INCH     // Four-drawer base
                                    + 42 * INCH;    // Corner sink

#declare KITCHEN_NW_CAB_WIDTH   = 42 * INCH         // Corner sink
                                    + 12 * INCH;    // Drawer/door base
                                    
#declare KITCHEN_SW_CAB_WIDTH   = 36 * INCH         // Corner lazy susan
                                    + 18 * INCH;    // 4-drawer base

#declare KITCHEN_E_CAB_LENGTH   = 39 * INCH         // Refrigerator
                                    + 3 * 30 * INCH // drawer/door bases
                                    + 24 * INCH     // Pantry
                                    + 12 * INCH;    // End corner unit

#declare KITCHEN_WIDTH			= AS_INCHES(10, 2.5);
#declare KITCHEN_DEPTH          = KITCHEN_W_CAB_LENGTH + WALL_THICKNESS;

#declare OFFICE_INSIDE_WIDTH	= KITCHEN_WIDTH + WALL_THICKNESS;
#declare OFFICE_INSIDE_DEPTH	= AS_INCHES(13, 6);

#declare ENTRY_HALL_LENGTH      = AS_INCHES(15, 0);
#declare ENTRY_HALL_WIDTH		= AS_INCHES(4, 0);

#declare WIDTH_TO_STAIRWELL		= OFFICE_INSIDE_WIDTH + ENTRY_HALL_WIDTH;
#declare STAIR_WIDTH			= AS_INCHES(3, 2.5);
#declare STAIR_RAIL_WIDTH		= 3.5 * INCH;
#declare STAIRWELL_WIDTH		= (STAIR_WIDTH + STAIR_RAIL_WIDTH) * 2;
#declare STAIRWELL_DEPTH        = AS_INCHES(8, 3);

#declare LANDING_DEPTH          = AS_INCHES(3, 6);
#declare LANDING_WIDTH          = STAIRWELL_WIDTH - STAIR_RAIL_WIDTH;

#declare STAIR_HEIGHT           = WALL_HEIGHT / 2;
#declare STAIR_DEPTH            = STAIRWELL_DEPTH - LANDING_DEPTH;
#declare NUM_RISERS             = 7;
#declare NUM_TREADS             = NUM_RISERS - 1;
#declare RISER_HEIGHT           = STAIR_HEIGHT / NUM_RISERS;
#declare TREAD_DEPTH            = STAIR_DEPTH / NUM_TREADS;
#declare STAIR_PITCH            = degrees(atan2(RISER_HEIGHT, TREAD_DEPTH));

#declare SUNROOM_WIDTH			= AS_INCHES(12, 8.5);
#declare SUNROOM_DEPTH	        = AS_INCHES(11, 8.5);
#declare WIDTH_TO_SUNROOM       = WIDTH_TO_STAIRWELL
									+ STAIRWELL_WIDTH;

#declare HOUSE_INSIDE_WIDTH		= WIDTH_TO_SUNROOM
									+ WALL_THICKNESS
									+ SUNROOM_WIDTH;
#declare HOUSE_INSIDE_DEPTH		= AS_INCHES(53, 4);

#declare HOUSE_OUTSIDE_WIDTH    = HOUSE_INSIDE_WIDTH + (2 * WALL_THICKNESS);
#declare HOUSE_OUTSIDE_DEPTH    = HOUSE_INSIDE_DEPTH + (2 * WALL_THICKNESS);

#declare GREAT_ROOM_WIDTH       = HOUSE_INSIDE_WIDTH
                                    - SUNROOM_WIDTH
                                    - WALL_THICKNESS;
#declare GREAT_ROOM_DEPTH       = HOUSE_INSIDE_DEPTH
                                    - OFFICE_INSIDE_DEPTH
                                    - KITCHEN_DEPTH
                                    - WALL_THICKNESS;

#declare FIREPLACE_OFS          = AS_INCHES(10, 11);
#declare FIREPLACE_WIDTH        = AS_INCHES(5, 4);
#declare FIREPLACE_HEIGHT       = AS_INCHES(4, 7.5);

#declare GUEST_BATH_WIDTH		= AS_INCHES(5, 5.5);
#declare GUEST_BATH_DEPTH		= AS_INCHES(8, 4);

#declare LAUNDRY_RM_WIDTH		= AS_INCHES(7, 3.5);
#declare LAUNDRY_RM_DEPTH		= AS_INCHES(8, 8.5);

#declare GUEST_BR_HALL_WIDTH	= AS_INCHES(3, 4);
#declare GUEST_BR_HALL_LENGTH   = WALL_THICKNESS + LAUNDRY_RM_WIDTH;
#declare WIDTH_TO_GUEST_BR      = WIDTH_TO_STAIRWELL + GUEST_BR_HALL_LENGTH;

#declare COAT_CLOSET_WIDTH      = AS_INCHES(3, 3.5);
#declare COAT_CLOSET_DEPTH      = AS_INCHES(2, 1);
#declare WIDTH_TO_COAT_CLOSET   = WIDTH_TO_GUEST_BR
                                    - COAT_CLOSET_WIDTH
                                    - WALL_THICKNESS;
                                    
#declare GUEST_BR_WIDTH			= AS_INCHES(12, 1);
#declare GUEST_BR_DEPTH         = AS_INCHES(12, 1);
#declare GUEST_BR_CLOSET_WIDTH  = AS_INCHES(8, 5.5);
#declare GUEST_BR_CLOSET_DEPTH  = AS_INCHES(2, 1);

                                    
#declare M_BR_WIDTH				= SUNROOM_WIDTH;
#declare M_BR_DEPTH				= AS_INCHES(15, 11);
#declare M_BR_HALL_WIDTH		= AS_INCHES(3, 8.5);
#declare M_BR_HALL_LENGTH       = AS_INCHES(3, 5);

#declare M_BATH_WIDTH			= AS_INCHES(8, 0);
#declare M_BATH_DEPTH           = HOUSE_INSIDE_DEPTH
                                    - SUNROOM_DEPTH
                                    - M_BR_DEPTH
                                    - GUEST_BR_DEPTH
                                    - GUEST_BR_CLOSET_DEPTH
                                    - (4 * WALL_THICKNESS);

#declare M_SHOWER_WIDTH			= AS_INCHES(4, 0);
#declare M_SHOWER_DEPTH			= AS_INCHES(4, 0);

#declare LINEN_CLOSET_WIDTH		= M_BATH_WIDTH
    							    - M_SHOWER_WIDTH
									- WALL_THICKNESS;
#declare M_BATH_COUNTER_DEPTH   = AS_INCHES(1, 10);
#declare LINEN_CLOSET_DEPTH		= M_BATH_COUNTER_DEPTH
								    - WALL_THICKNESS;
#declare M_BATH_VANITY_LENGTH   = M_BATH_DEPTH
                                    - M_SHOWER_DEPTH
                                    - WALL_THICKNESS;

#declare DIST_TO_GUEST_BR_S_HALL    = LAUNDRY_RM_DEPTH
                                        + COAT_CLOSET_DEPTH
                                        + WALL_THICKNESS;

#declare DIST_TO_GUEST_BR_N_HALL    = DIST_TO_GUEST_BR_S_HALL
                                        + GUEST_BR_HALL_WIDTH
                                        + WALL_THICKNESS;

#declare DIST_TO_M_BR_S_HALL        = DIST_TO_GUEST_BR_N_HALL
                                        + WALL_THICKNESS
                                        + GUEST_BATH_DEPTH;

#declare DIST_TO_M_BR_N_HALL        = DIST_TO_M_BR_S_HALL
                                        + M_BR_HALL_WIDTH
                                        + WALL_THICKNESS;
                                        
#declare DIST_TO_STAIRWELL          = DIST_TO_M_BR_N_HALL + WALL_THICKNESS;

#declare M_BR_N_WALL_DIST           = HOUSE_INSIDE_DEPTH
                                        - SUNROOM_DEPTH
                                        - WALL_THICKNESS;
#declare M_BR_WEST_WALL_LENGTH	    = M_BR_N_WALL_DIST - DIST_TO_M_BR_N_HALL;

#declare M_CLOSET_WIDTH			    = HOUSE_INSIDE_WIDTH
                                        - M_BATH_WIDTH
                                        - WIDTH_TO_STAIRWELL
                                        - GUEST_BATH_WIDTH
                                        - 3 * WALL_THICKNESS;
#declare M_CLOSET_DEPTH			    = GUEST_BATH_DEPTH;


// Lower floor.
#declare LOWER_BR_WIDTH             = AS_INCHES(11, 8.5);
#declare LOWER_BR_DEPTH             = AS_INCHES(13, 7);

#declare LOWER_BR_CLOSET_WIDTH      = AS_INCHES(4, 7);
#declare LOWER_BR_CLOSET_DEPTH      = AS_INCHES(5, 0.5);

#declare LOWER_BATH_WIDTH           = AS_INCHES(8, 2);
#declare LOWER_BATH_DEPTH           = LOWER_BR_CLOSET_DEPTH;

#declare REC_RM_MAIN_WIDTH          = HOUSE_INSIDE_WIDTH
                                        - LOWER_BR_CLOSET_WIDTH
                                        - WALL_THICKNESS;
#declare REC_RM_MAIN_DEPTH          = AS_INCHES(17, 9);
#declare REC_RM_BACK_WIDTH          = HOUSE_INSIDE_WIDTH
                                        - AS_INCHES(21, 8.5);
#declare REC_RM_BACK_DEPTH          = AS_INCHES(8, 6.5);

#declare DIST_LOWER_BR_WALL         = HOUSE_INSIDE_DEPTH
                                        - LOWER_BR_DEPTH
                                        - WALL_THICKNESS;
#declare DIST_REC_RM_BACK           = HOUSE_INSIDE_DEPTH
                                        - REC_RM_MAIN_DEPTH
                                        - REC_RM_BACK_DEPTH
                                        - WALL_THICKNESS;
#declare DIST_LOWER_BATH_BACK_WALL  = DIST_LOWER_BR_WALL
                                        - LOWER_BATH_DEPTH
                                        - WALL_THICKNESS;

#declare KITCHEN_HALF_WALL_HEIGHT   = AS_INCHES(3, 6);
#declare KITCHEN_HALF_WALL_LENGTH   = KITCHEN_NW_CAB_WIDTH + 1 * INCH;


//////////////////////////////////////////////////////////////////////////
// Door opening widths.

#declare FRONT_DOOR_WIDTH               = 36 * INCH;
#declare KITCHEN_DOOR_WIDTH             = 36 * INCH;
#declare SUNROOM_ENTRY_WIDTH            = 72 * INCH;
#declare SUNROOM_M_BR_DOOR_WIDTH        = AS_INCHES(2, 6);
#declare SUNROOM_M_BR_OPENING_WIDTH     = 2 * SUNROOM_M_BR_DOOR_WIDTH;
#declare M_BATH_DOOR_WIDTH              = AS_INCHES(2, 3);
#declare M_SHOWER_DOOR_WIDTH            = AS_INCHES(2, 3);
#declare LINEN_CLOSET_DOOR_WIDTH        = AS_INCHES(2, 3);
#declare M_BR_DOOR_WIDTH                = AS_INCHES(2, 6);
#declare M_BR_CLOSET_DOOR_WIDTH         = AS_INCHES(2, 6);
#declare GUEST_BATH_DOOR_WIDTH          = AS_INCHES(2, 3);
#declare LAUNDRY_RM_DOOR_WIDTH          = AS_INCHES(2, 6);
#declare COAT_CLOSET_DOOR_WIDTH         = AS_INCHES(2, 3);
#declare GUEST_BR_DOOR_WIDTH            = AS_INCHES(2, 6);
#declare GUEST_BR_CLOSET_OPENING_WIDTH  = 70 * INCH;    // 2 sliding doors
#declare GUEST_BR_CLOSET_DOOR_WIDTH     = 36 * INCH;
#declare GARAGE_DOOR_WIDTH              = 36 * INCH;

#declare LOWER_BR_DOOR_WIDTH            = AS_INCHES(2, 6);
#declare LOWER_BR_CLOSET_DOOR_WIDTH     = AS_INCHES(2, 3);
#declare LOWER_BATH_DOOR_WIDTH          = AS_INCHES(2, 3);
#declare REC_ROOM_BACK_DOOR_WIDTH       = AS_INCHES(3, 0);


//////////////////////////////////////////////////////////////////////////
// Door opening center offsets, relative to the wall's origin.

#declare FRONT_DOOR_OFS                 = AS_INCHES(3, 3.5);
#declare KITCHEN_DOOR_OFS               = 56 * INCH
                                            + KITCHEN_DOOR_WIDTH / 2
                                            + FRAME_TRIM_WIDTH;
#declare SUNROOM_ENTRY_OFS              = SUNROOM_DEPTH / 2;
#declare SUNROOM_M_BR_DOOR_OPENING_OFS  = (SUNROOM_WIDTH / 2) + WALL_THICKNESS;
#declare M_BATH_DOOR_OFS                = (M_BATH_WIDTH / 2) + WALL_THICKNESS;
#declare LINEN_CLOSET_DOOR_OFS          = (LINEN_CLOSET_WIDTH / 2) + WALL_THICKNESS;
#declare M_BR_CLOSET_DOOR_OFS           = (M_CLOSET_WIDTH / 2) + WALL_THICKNESS;
#declare M_BR_DOOR_OFS                  = M_BR_HALL_WIDTH / 2;
#declare GUEST_BATH_DOOR_OFS            = GUEST_BATH_WIDTH
                                            -GUEST_BATH_DOOR_WIDTH / 2
                                            - 4 * INCH
                                            + WALL_THICKNESS;

#declare LAUNDRY_RM_DOOR_OFS            = WALL_THICKNESS
                                            + (4 * INCH)
                                            + (LAUNDRY_RM_DOOR_WIDTH / 2);
#declare COAT_CLOSET_DOOR_OFS           = GUEST_BR_HALL_LENGTH
                                            - (COAT_CLOSET_WIDTH / 2);

#declare GUEST_BR_DOOR_OFS              = GUEST_BR_HALL_WIDTH / 2;
#declare GUEST_BR_CLOSET_OPENING_OFS    = GUEST_BR_CLOSET_WIDTH / 2;

#declare GARAGE_DOOR_OFS                = WALL_THICKNESS
                                            + (4 * INCH)
                                            + (GARAGE_DOOR_WIDTH / 2);

#declare LOWER_BR_DOOR_OFS              = LOWER_BR_DEPTH
                                            - (LOWER_BR_DOOR_WIDTH / 2)
                                            - WALL_THICKNESS;
#declare LOWER_BR_CLOSET_DOOR_OFS       = LOWER_BR_CLOSET_WIDTH
                                            - (LOWER_BR_CLOSET_DOOR_WIDTH / 2)
                                            - WALL_THICKNESS;
#declare LOWER_BATH_DOOR_OFS            = (LOWER_BATH_DOOR_WIDTH / 2)
                                            + WALL_THICKNESS;
#declare REC_ROOM_BACK_DOOR_OFS         = (REC_ROOM_BACK_DOOR_WIDTH / 2)
                                            + WALL_THICKNESS;


//////////////////////////////////////////////////////////////////////////
// Window opening widths.

#declare GREAT_ROOM_WINDOW_WIDTH    = 32 * INCH;
#declare SUNROOM_WINDOW_WIDTH       = 24 * INCH;
#declare M_BR_WINDOW_WIDTH          = 24 * INCH;
#declare M_BATH_WINDOW_WIDTH        = 32 * INCH;
#declare M_BATH_WINDOW_HEIGHT       = 30 * INCH;
#declare M_BATH_WINDOW_BOTTOM       = DOOR_HEIGHT - M_BATH_WINDOW_HEIGHT;
#declare GUEST_BR_WINDOW_WIDTH      = 24 * INCH;
#declare OFFICE_WINDOW_WIDTH        = 24 * INCH;

#declare LOWER_BR_WINDOW_WIDTH      = 32 * INCH;


//////////////////////////////////////////////////////////////////////////
// Window opening center offsets, relative to the origin of
// the wall containing them.

#declare GREAT_ROOM_W_WINDOW_OFS    = FIREPLACE_OFS
										- (FIREPLACE_WIDTH / 2)
										- AS_INCHES(4, 3)
										+ (GREAT_ROOM_WINDOW_WIDTH / 2);
#declare GREAT_ROOM_E_WINDOW_OFS    = FIREPLACE_OFS
										+ (FIREPLACE_WIDTH / 2)
										+ AS_INCHES(4, 3)
										- (GREAT_ROOM_WINDOW_WIDTH / 2);

#declare SUNROOM_NW_WINDOW_OFS      = AS_INCHES(2, 1);
#declare SUNROOM_NM_WINDOW_OFS      = AS_INCHES(6, 6);
#declare SUNROOM_NE_WINDOW_OFS      = AS_INCHES(10, 11);
#declare SUNROOM_EN_WINDOW_OFS      = AS_INCHES(2, 0);
#declare SUNROOM_EM_WINDOW_OFS      = AS_INCHES(5, 10.5);
#declare SUNROOM_ES_WINDOW_OFS      = AS_INCHES(9, 8.5);

#declare M_BR_N_WINDOW_OFS          = AS_INCHES(3, 0);
#declare M_BR_S_WINDOW_OFS          = M_BR_N_WINDOW_OFS + AS_INCHES(11, 2);

#declare M_BATH_WINDOW_OFS          = AS_INCHES(3, 5.5);

#declare GUEST_BR_N_WINDOW_OFS      = AS_INCHES(8, 0.5);
#declare GUEST_BR_S_WINDOW_OFS      = AS_INCHES(10, 1.5);

#declare OFFICE_E_WINDOW_OFS        = AS_INCHES(8, 3.5);
#declare OFFICE_W_WINDOW_OFS        = AS_INCHES(12, 3.5);

#declare LOWER_BR_WINDOW_OFS        = AS_INCHES(4, 0.5);


//////////////////////////////////////////////////////////////////////////
// Furniture dimensions.                                                //

#declare MATTRESS_THICK                 = 8 * INCH;

#declare BED_HEADBOARD_THICK            = 1.5 * INCH;
#declare BED_FRAME_HGT_OFF_FLOOR        = 8 * INCH;
#declare BED_HEADBOARD_HGT              = BED_FRAME_HGT_OFF_FLOOR
                                            + (4 * MATTRESS_THICK);
#declare BED_FOOT_BOARD_HGT             = BED_FRAME_HGT_OFF_FLOOR
                                            + (2.5 * MATTRESS_THICK);

#declare TWIN_MATTRESS_WID              = 39 * INCH;
#declare TWIN_MATTRESS_LEN              = 75 * INCH;
#declare TWIN_HEADBOARD_WIDTH           = TWIN_MATTRESS_WID
                                            + (2 * BED_HEADBOARD_THICK);

#declare DBL_MATTRESS_WID               = 54 * INCH;
#declare DBL_MATTRESS_LEN               = 75 * INCH;
#declare DBL_HEADBOARD_WIDTH            = DBL_MATTRESS_WID
                                            + (2 * BED_HEADBOARD_THICK);

#declare QUEEN_MATTRESS_WID             = 60 * INCH;
#declare QUEEN_MATTRESS_LEN             = 80 * INCH;
#declare QUEEN_HEADBOARD_WIDTH          = QUEEN_MATTRESS_WID
                                            + (2 * BED_HEADBOARD_THICK);
                                            
#declare KING_MATTRESS_WID              = 76 * INCH;
#declare KING_MATTRESS_LEN              = 80 * INCH;
#declare KING_HEADBOARD_WIDTH           = KING_MATTRESS_WID
                                            + (2 * BED_HEADBOARD_THICK);

#declare WIDTH_TO_DINING_TABLE          = 56 * INCH;
#declare DIST_TO_DINING_TABLE           = OFFICE_INSIDE_DEPTH
                                                + WALL_THICKNESS
                                                + KITCHEN_DEPTH
                                                + 56 * INCH;

#end    // #ifndef (_Measurements_inc_)
