/* BM defined */

#include "bondmachineip1.h"  
#include "xil_io.h"  
#include "xparameters.h"

// if used will remove all the control registers
//#define REMOVE_CONTROL_CHECK 1

#define BM_UPPER_IN_REG_LIMIT 127
#define BM_LOWER_IN_REG_LIMIT 0

#define BM_UPPER_OUT_REG_LIMIT 127
#define BM_LOWER_OUT_REG_LIMIT 0

#define REGISTER_SIZE 32
#define BM_DATA_VALID 0
#define BM_DATA_RECV 1

#define BM_SPLIT_CTRL_REGISTERS 1 /* if set BM_DATA_VALID and BM_DATA_RECV will be both 0 */

#define BM_IN_CTRL_0 0x00000000
#define BM_IN_CTRL_1 0x00000000
#define BM_IN_CTRL_2 0x00000000
#define BM_IN_CTRL_3 0x00000000
#define BM_IN_CTRL_4 0x00000000
#define BM_IN_CTRL_5 0x00000000
#define BM_IN_CTRL_6 0x00000000
#define BM_IN_CTRL_7 0x00000000
#define BM_IN_CTRL_8 0x00000000
#define BM_IN_CTRL_9 0x00000000
#define BM_IN_CTRL_10 0x00000000
#define BM_IN_CTRL_11 0x00000000
#define BM_IN_CTRL_12 0x00000000
#define BM_IN_CTRL_13 0x00000000
#define BM_IN_CTRL_14 0x00000000
#define BM_IN_CTRL_15 0x00000000
#define BM_IN_CTRL_16 0x00000000
#define BM_IN_CTRL_17 0x00000000
#define BM_IN_CTRL_18 0x00000000
#define BM_IN_CTRL_19 0x00000000
#define BM_IN_CTRL_20 0x00000000
#define BM_IN_CTRL_21 0x00000000
#define BM_IN_CTRL_22 0x00000000
#define BM_IN_CTRL_23 0x00000000
#define BM_IN_CTRL_24 0x00000000
#define BM_IN_CTRL_25 0x00000000
#define BM_IN_CTRL_26 0x00000000
#define BM_IN_CTRL_27 0x00000000
#define BM_IN_CTRL_28 0x00000000
#define BM_IN_CTRL_29 0x00000000
#define BM_IN_CTRL_30 0x00000000
#define BM_IN_CTRL_31 0x00000000
#define BM_IN_CTRL_32 0x00000000
#define BM_IN_CTRL_33 0x00000000
#define BM_IN_CTRL_34 0x00000000
#define BM_IN_CTRL_35 0x00000000
#define BM_IN_CTRL_36 0x00000000
#define BM_IN_CTRL_37 0x00000000
#define BM_IN_CTRL_38 0x00000000
#define BM_IN_CTRL_39 0x00000000
#define BM_IN_CTRL_40 0x00000000
#define BM_IN_CTRL_41 0x00000000
#define BM_IN_CTRL_42 0x00000000
#define BM_IN_CTRL_43 0x00000000
#define BM_IN_CTRL_44 0x00000000
#define BM_IN_CTRL_45 0x00000000
#define BM_IN_CTRL_46 0x00000000
#define BM_IN_CTRL_47 0x00000000
#define BM_IN_CTRL_48 0x00000000
#define BM_IN_CTRL_49 0x00000000
#define BM_IN_CTRL_50 0x00000000
#define BM_IN_CTRL_51 0x00000000
#define BM_IN_CTRL_52 0x00000000
#define BM_IN_CTRL_53 0x00000000
#define BM_IN_CTRL_54 0x00000000
#define BM_IN_CTRL_55 0x00000000
#define BM_IN_CTRL_56 0x00000000
#define BM_IN_CTRL_57 0x00000000
#define BM_IN_CTRL_58 0x00000000
#define BM_IN_CTRL_59 0x00000000
#define BM_IN_CTRL_60 0x00000000
#define BM_IN_CTRL_61 0x00000000
#define BM_IN_CTRL_62 0x00000000
#define BM_IN_CTRL_63 0x00000000
#define BM_IN_CTRL_64 0x00000000
#define BM_IN_CTRL_65 0x00000000
#define BM_IN_CTRL_66 0x00000000
#define BM_IN_CTRL_67 0x00000000
#define BM_IN_CTRL_68 0x00000000
#define BM_IN_CTRL_69 0x00000000
#define BM_IN_CTRL_70 0x00000000
#define BM_IN_CTRL_71 0x00000000
#define BM_IN_CTRL_72 0x00000000
#define BM_IN_CTRL_73 0x00000000
#define BM_IN_CTRL_74 0x00000000
#define BM_IN_CTRL_75 0x00000000
#define BM_IN_CTRL_76 0x00000000
#define BM_IN_CTRL_77 0x00000000
#define BM_IN_CTRL_78 0x00000000
#define BM_IN_CTRL_79 0x00000000
#define BM_IN_CTRL_80 0x00000000
#define BM_IN_CTRL_81 0x00000000
#define BM_IN_CTRL_82 0x00000000
#define BM_IN_CTRL_83 0x00000000
#define BM_IN_CTRL_84 0x00000000
#define BM_IN_CTRL_85 0x00000000
#define BM_IN_CTRL_86 0x00000000
#define BM_IN_CTRL_87 0x00000000
#define BM_IN_CTRL_88 0x00000000
#define BM_IN_CTRL_89 0x00000000
#define BM_IN_CTRL_90 0x00000000
#define BM_IN_CTRL_91 0x00000000
#define BM_IN_CTRL_92 0x00000000
#define BM_IN_CTRL_93 0x00000000
#define BM_IN_CTRL_94 0x00000000
#define BM_IN_CTRL_95 0x00000000
#define BM_IN_CTRL_96 0x00000000
#define BM_IN_CTRL_97 0x00000000
#define BM_IN_CTRL_98 0x00000000
#define BM_IN_CTRL_99 0x00000000
#define BM_IN_CTRL_100 0x00000000
#define BM_IN_CTRL_101 0x00000000
#define BM_IN_CTRL_102 0x00000000
#define BM_IN_CTRL_103 0x00000000
#define BM_IN_CTRL_104 0x00000000
#define BM_IN_CTRL_105 0x00000000
#define BM_IN_CTRL_106 0x00000000
#define BM_IN_CTRL_107 0x00000000
#define BM_IN_CTRL_108 0x00000000
#define BM_IN_CTRL_109 0x00000000
#define BM_IN_CTRL_110 0x00000000
#define BM_IN_CTRL_111 0x00000000
#define BM_IN_CTRL_112 0x00000000
#define BM_IN_CTRL_113 0x00000000
#define BM_IN_CTRL_114 0x00000000
#define BM_IN_CTRL_115 0x00000000
#define BM_IN_CTRL_116 0x00000000
#define BM_IN_CTRL_117 0x00000000
#define BM_IN_CTRL_118 0x00000000
#define BM_IN_CTRL_119 0x00000000
#define BM_IN_CTRL_120 0x00000000
#define BM_IN_CTRL_121 0x00000000
#define BM_IN_CTRL_122 0x00000000
#define BM_IN_CTRL_123 0x00000000
#define BM_IN_CTRL_124 0x00000000
#define BM_IN_CTRL_125 0x00000000
#define BM_IN_CTRL_126 0x00000000
#define BM_IN_CTRL_127 0x00000000

#define BM_IN_DATA_VALID_0 0x00000000
#define BM_IN_DATA_VALID_1 0x00000000
#define BM_IN_DATA_VALID_2 0x00000000
#define BM_IN_DATA_VALID_3 0x00000000
#define BM_IN_DATA_VALID_4 0x00000000
#define BM_IN_DATA_VALID_5 0x00000000
#define BM_IN_DATA_VALID_6 0x00000000
#define BM_IN_DATA_VALID_7 0x00000000
#define BM_IN_DATA_VALID_8 0x00000000
#define BM_IN_DATA_VALID_9 0x00000000
#define BM_IN_DATA_VALID_10 0x00000000
#define BM_IN_DATA_VALID_11 0x00000000
#define BM_IN_DATA_VALID_12 0x00000000
#define BM_IN_DATA_VALID_13 0x00000000
#define BM_IN_DATA_VALID_14 0x00000000
#define BM_IN_DATA_VALID_15 0x00000000
#define BM_IN_DATA_VALID_16 0x00000000
#define BM_IN_DATA_VALID_17 0x00000000
#define BM_IN_DATA_VALID_18 0x00000000
#define BM_IN_DATA_VALID_19 0x00000000
#define BM_IN_DATA_VALID_20 0x00000000
#define BM_IN_DATA_VALID_21 0x00000000
#define BM_IN_DATA_VALID_22 0x00000000
#define BM_IN_DATA_VALID_23 0x00000000
#define BM_IN_DATA_VALID_24 0x00000000
#define BM_IN_DATA_VALID_25 0x00000000
#define BM_IN_DATA_VALID_26 0x00000000
#define BM_IN_DATA_VALID_27 0x00000000
#define BM_IN_DATA_VALID_28 0x00000000
#define BM_IN_DATA_VALID_29 0x00000000
#define BM_IN_DATA_VALID_30 0x00000000
#define BM_IN_DATA_VALID_31 0x00000000
#define BM_IN_DATA_VALID_32 0x00000000
#define BM_IN_DATA_VALID_33 0x00000000
#define BM_IN_DATA_VALID_34 0x00000000
#define BM_IN_DATA_VALID_35 0x00000000
#define BM_IN_DATA_VALID_36 0x00000000
#define BM_IN_DATA_VALID_37 0x00000000
#define BM_IN_DATA_VALID_38 0x00000000
#define BM_IN_DATA_VALID_39 0x00000000
#define BM_IN_DATA_VALID_40 0x00000000
#define BM_IN_DATA_VALID_41 0x00000000
#define BM_IN_DATA_VALID_42 0x00000000
#define BM_IN_DATA_VALID_43 0x00000000
#define BM_IN_DATA_VALID_44 0x00000000
#define BM_IN_DATA_VALID_45 0x00000000
#define BM_IN_DATA_VALID_46 0x00000000
#define BM_IN_DATA_VALID_47 0x00000000
#define BM_IN_DATA_VALID_48 0x00000000
#define BM_IN_DATA_VALID_49 0x00000000
#define BM_IN_DATA_VALID_50 0x00000000
#define BM_IN_DATA_VALID_51 0x00000000
#define BM_IN_DATA_VALID_52 0x00000000
#define BM_IN_DATA_VALID_53 0x00000000
#define BM_IN_DATA_VALID_54 0x00000000
#define BM_IN_DATA_VALID_55 0x00000000
#define BM_IN_DATA_VALID_56 0x00000000
#define BM_IN_DATA_VALID_57 0x00000000
#define BM_IN_DATA_VALID_58 0x00000000
#define BM_IN_DATA_VALID_59 0x00000000
#define BM_IN_DATA_VALID_60 0x00000000
#define BM_IN_DATA_VALID_61 0x00000000
#define BM_IN_DATA_VALID_62 0x00000000
#define BM_IN_DATA_VALID_63 0x00000000
#define BM_IN_DATA_VALID_64 0x00000000
#define BM_IN_DATA_VALID_65 0x00000000
#define BM_IN_DATA_VALID_66 0x00000000
#define BM_IN_DATA_VALID_67 0x00000000
#define BM_IN_DATA_VALID_68 0x00000000
#define BM_IN_DATA_VALID_69 0x00000000
#define BM_IN_DATA_VALID_70 0x00000000
#define BM_IN_DATA_VALID_71 0x00000000
#define BM_IN_DATA_VALID_72 0x00000000
#define BM_IN_DATA_VALID_73 0x00000000
#define BM_IN_DATA_VALID_74 0x00000000
#define BM_IN_DATA_VALID_75 0x00000000
#define BM_IN_DATA_VALID_76 0x00000000
#define BM_IN_DATA_VALID_77 0x00000000
#define BM_IN_DATA_VALID_78 0x00000000
#define BM_IN_DATA_VALID_79 0x00000000
#define BM_IN_DATA_VALID_80 0x00000000
#define BM_IN_DATA_VALID_81 0x00000000
#define BM_IN_DATA_VALID_82 0x00000000
#define BM_IN_DATA_VALID_83 0x00000000
#define BM_IN_DATA_VALID_84 0x00000000
#define BM_IN_DATA_VALID_85 0x00000000
#define BM_IN_DATA_VALID_86 0x00000000
#define BM_IN_DATA_VALID_87 0x00000000
#define BM_IN_DATA_VALID_88 0x00000000
#define BM_IN_DATA_VALID_89 0x00000000
#define BM_IN_DATA_VALID_90 0x00000000
#define BM_IN_DATA_VALID_91 0x00000000
#define BM_IN_DATA_VALID_92 0x00000000
#define BM_IN_DATA_VALID_93 0x00000000
#define BM_IN_DATA_VALID_94 0x00000000
#define BM_IN_DATA_VALID_95 0x00000000
#define BM_IN_DATA_VALID_96 0x00000000
#define BM_IN_DATA_VALID_97 0x00000000
#define BM_IN_DATA_VALID_98 0x00000000
#define BM_IN_DATA_VALID_99 0x00000000
#define BM_IN_DATA_VALID_100 0x00000000
#define BM_IN_DATA_VALID_101 0x00000000
#define BM_IN_DATA_VALID_102 0x00000000
#define BM_IN_DATA_VALID_103 0x00000000
#define BM_IN_DATA_VALID_104 0x00000000
#define BM_IN_DATA_VALID_105 0x00000000
#define BM_IN_DATA_VALID_106 0x00000000
#define BM_IN_DATA_VALID_107 0x00000000
#define BM_IN_DATA_VALID_108 0x00000000
#define BM_IN_DATA_VALID_109 0x00000000
#define BM_IN_DATA_VALID_110 0x00000000
#define BM_IN_DATA_VALID_111 0x00000000
#define BM_IN_DATA_VALID_112 0x00000000
#define BM_IN_DATA_VALID_113 0x00000000
#define BM_IN_DATA_VALID_114 0x00000000
#define BM_IN_DATA_VALID_115 0x00000000
#define BM_IN_DATA_VALID_116 0x00000000
#define BM_IN_DATA_VALID_117 0x00000000
#define BM_IN_DATA_VALID_118 0x00000000
#define BM_IN_DATA_VALID_119 0x00000000
#define BM_IN_DATA_VALID_120 0x00000000
#define BM_IN_DATA_VALID_121 0x00000000
#define BM_IN_DATA_VALID_122 0x00000000
#define BM_IN_DATA_VALID_123 0x00000000
#define BM_IN_DATA_VALID_124 0x00000000
#define BM_IN_DATA_VALID_125 0x00000000
#define BM_IN_DATA_VALID_126 0x00000000
#define BM_IN_DATA_VALID_127 0x00000000

#define BM_IN_DATA_RECV_0 0x00000000
#define BM_IN_DATA_RECV_1 0x00000000
#define BM_IN_DATA_RECV_2 0x00000000
#define BM_IN_DATA_RECV_3 0x00000000
#define BM_IN_DATA_RECV_4 0x00000000
#define BM_IN_DATA_RECV_5 0x00000000
#define BM_IN_DATA_RECV_6 0x00000000
#define BM_IN_DATA_RECV_7 0x00000000
#define BM_IN_DATA_RECV_8 0x00000000
#define BM_IN_DATA_RECV_9 0x00000000
#define BM_IN_DATA_RECV_10 0x00000000
#define BM_IN_DATA_RECV_11 0x00000000
#define BM_IN_DATA_RECV_12 0x00000000
#define BM_IN_DATA_RECV_13 0x00000000
#define BM_IN_DATA_RECV_14 0x00000000
#define BM_IN_DATA_RECV_15 0x00000000
#define BM_IN_DATA_RECV_16 0x00000000
#define BM_IN_DATA_RECV_17 0x00000000
#define BM_IN_DATA_RECV_18 0x00000000
#define BM_IN_DATA_RECV_19 0x00000000
#define BM_IN_DATA_RECV_20 0x00000000
#define BM_IN_DATA_RECV_21 0x00000000
#define BM_IN_DATA_RECV_22 0x00000000
#define BM_IN_DATA_RECV_23 0x00000000
#define BM_IN_DATA_RECV_24 0x00000000
#define BM_IN_DATA_RECV_25 0x00000000
#define BM_IN_DATA_RECV_26 0x00000000
#define BM_IN_DATA_RECV_27 0x00000000
#define BM_IN_DATA_RECV_28 0x00000000
#define BM_IN_DATA_RECV_29 0x00000000
#define BM_IN_DATA_RECV_30 0x00000000
#define BM_IN_DATA_RECV_31 0x00000000
#define BM_IN_DATA_RECV_32 0x00000000
#define BM_IN_DATA_RECV_33 0x00000000
#define BM_IN_DATA_RECV_34 0x00000000
#define BM_IN_DATA_RECV_35 0x00000000
#define BM_IN_DATA_RECV_36 0x00000000
#define BM_IN_DATA_RECV_37 0x00000000
#define BM_IN_DATA_RECV_38 0x00000000
#define BM_IN_DATA_RECV_39 0x00000000
#define BM_IN_DATA_RECV_40 0x00000000
#define BM_IN_DATA_RECV_41 0x00000000
#define BM_IN_DATA_RECV_42 0x00000000
#define BM_IN_DATA_RECV_43 0x00000000
#define BM_IN_DATA_RECV_44 0x00000000
#define BM_IN_DATA_RECV_45 0x00000000
#define BM_IN_DATA_RECV_46 0x00000000
#define BM_IN_DATA_RECV_47 0x00000000
#define BM_IN_DATA_RECV_48 0x00000000
#define BM_IN_DATA_RECV_49 0x00000000
#define BM_IN_DATA_RECV_50 0x00000000
#define BM_IN_DATA_RECV_51 0x00000000
#define BM_IN_DATA_RECV_52 0x00000000
#define BM_IN_DATA_RECV_53 0x00000000
#define BM_IN_DATA_RECV_54 0x00000000
#define BM_IN_DATA_RECV_55 0x00000000
#define BM_IN_DATA_RECV_56 0x00000000
#define BM_IN_DATA_RECV_57 0x00000000
#define BM_IN_DATA_RECV_58 0x00000000
#define BM_IN_DATA_RECV_59 0x00000000
#define BM_IN_DATA_RECV_60 0x00000000
#define BM_IN_DATA_RECV_61 0x00000000
#define BM_IN_DATA_RECV_62 0x00000000
#define BM_IN_DATA_RECV_63 0x00000000
#define BM_IN_DATA_RECV_64 0x00000000
#define BM_IN_DATA_RECV_65 0x00000000
#define BM_IN_DATA_RECV_66 0x00000000
#define BM_IN_DATA_RECV_67 0x00000000
#define BM_IN_DATA_RECV_68 0x00000000
#define BM_IN_DATA_RECV_69 0x00000000
#define BM_IN_DATA_RECV_70 0x00000000
#define BM_IN_DATA_RECV_71 0x00000000
#define BM_IN_DATA_RECV_72 0x00000000
#define BM_IN_DATA_RECV_73 0x00000000
#define BM_IN_DATA_RECV_74 0x00000000
#define BM_IN_DATA_RECV_75 0x00000000
#define BM_IN_DATA_RECV_76 0x00000000
#define BM_IN_DATA_RECV_77 0x00000000
#define BM_IN_DATA_RECV_78 0x00000000
#define BM_IN_DATA_RECV_79 0x00000000
#define BM_IN_DATA_RECV_80 0x00000000
#define BM_IN_DATA_RECV_81 0x00000000
#define BM_IN_DATA_RECV_82 0x00000000
#define BM_IN_DATA_RECV_83 0x00000000
#define BM_IN_DATA_RECV_84 0x00000000
#define BM_IN_DATA_RECV_85 0x00000000
#define BM_IN_DATA_RECV_86 0x00000000
#define BM_IN_DATA_RECV_87 0x00000000
#define BM_IN_DATA_RECV_88 0x00000000
#define BM_IN_DATA_RECV_89 0x00000000
#define BM_IN_DATA_RECV_90 0x00000000
#define BM_IN_DATA_RECV_91 0x00000000
#define BM_IN_DATA_RECV_92 0x00000000
#define BM_IN_DATA_RECV_93 0x00000000
#define BM_IN_DATA_RECV_94 0x00000000
#define BM_IN_DATA_RECV_95 0x00000000
#define BM_IN_DATA_RECV_96 0x00000000
#define BM_IN_DATA_RECV_97 0x00000000
#define BM_IN_DATA_RECV_98 0x00000000
#define BM_IN_DATA_RECV_99 0x00000000
#define BM_IN_DATA_RECV_100 0x00000000
#define BM_IN_DATA_RECV_101 0x00000000
#define BM_IN_DATA_RECV_102 0x00000000
#define BM_IN_DATA_RECV_103 0x00000000
#define BM_IN_DATA_RECV_104 0x00000000
#define BM_IN_DATA_RECV_105 0x00000000
#define BM_IN_DATA_RECV_106 0x00000000
#define BM_IN_DATA_RECV_107 0x00000000
#define BM_IN_DATA_RECV_108 0x00000000
#define BM_IN_DATA_RECV_109 0x00000000
#define BM_IN_DATA_RECV_110 0x00000000
#define BM_IN_DATA_RECV_111 0x00000000
#define BM_IN_DATA_RECV_112 0x00000000
#define BM_IN_DATA_RECV_113 0x00000000
#define BM_IN_DATA_RECV_114 0x00000000
#define BM_IN_DATA_RECV_115 0x00000000
#define BM_IN_DATA_RECV_116 0x00000000
#define BM_IN_DATA_RECV_117 0x00000000
#define BM_IN_DATA_RECV_118 0x00000000
#define BM_IN_DATA_RECV_119 0x00000000
#define BM_IN_DATA_RECV_120 0x00000000
#define BM_IN_DATA_RECV_121 0x00000000
#define BM_IN_DATA_RECV_122 0x00000000
#define BM_IN_DATA_RECV_123 0x00000000
#define BM_IN_DATA_RECV_124 0x00000000
#define BM_IN_DATA_RECV_125 0x00000000
#define BM_IN_DATA_RECV_126 0x00000000
#define BM_IN_DATA_RECV_127 0x00000000

//#define BM_IN_DATA_0 0x00000000
#define BM_IN_DATA_0 (XPAR_BONDMACHINEIP1_0_S00_AXI_BASEADDR + BONDMACHINEIP1_S00_AXI_SLV_REG0_OFFSET)
//enum { BM_IN_DATA_0 = (LED_BASE + BONDMACHINEIP1_S00_AXI_SLV_REG0_OFFSET), };

#define BM_IN_DATA_1 0x00000000
#define BM_IN_DATA_2 0x00000000
#define BM_IN_DATA_3 0x00000000
#define BM_IN_DATA_4 0x00000000
#define BM_IN_DATA_5 0x00000000
#define BM_IN_DATA_6 0x00000000
#define BM_IN_DATA_7 0x00000000
#define BM_IN_DATA_8 0x00000000
#define BM_IN_DATA_9 0x00000000
#define BM_IN_DATA_10 0x00000000
#define BM_IN_DATA_11 0x00000000
#define BM_IN_DATA_12 0x00000000
#define BM_IN_DATA_13 0x00000000
#define BM_IN_DATA_14 0x00000000
#define BM_IN_DATA_15 0x00000000
#define BM_IN_DATA_16 0x00000000
#define BM_IN_DATA_17 0x00000000
#define BM_IN_DATA_18 0x00000000
#define BM_IN_DATA_19 0x00000000
#define BM_IN_DATA_20 0x00000000
#define BM_IN_DATA_21 0x00000000
#define BM_IN_DATA_22 0x00000000
#define BM_IN_DATA_23 0x00000000
#define BM_IN_DATA_24 0x00000000
#define BM_IN_DATA_25 0x00000000
#define BM_IN_DATA_26 0x00000000
#define BM_IN_DATA_27 0x00000000
#define BM_IN_DATA_28 0x00000000
#define BM_IN_DATA_29 0x00000000
#define BM_IN_DATA_30 0x00000000
#define BM_IN_DATA_31 0x00000000
#define BM_IN_DATA_32 0x00000000
#define BM_IN_DATA_33 0x00000000
#define BM_IN_DATA_34 0x00000000
#define BM_IN_DATA_35 0x00000000
#define BM_IN_DATA_36 0x00000000
#define BM_IN_DATA_37 0x00000000
#define BM_IN_DATA_38 0x00000000
#define BM_IN_DATA_39 0x00000000
#define BM_IN_DATA_40 0x00000000
#define BM_IN_DATA_41 0x00000000
#define BM_IN_DATA_42 0x00000000
#define BM_IN_DATA_43 0x00000000
#define BM_IN_DATA_44 0x00000000
#define BM_IN_DATA_45 0x00000000
#define BM_IN_DATA_46 0x00000000
#define BM_IN_DATA_47 0x00000000
#define BM_IN_DATA_48 0x00000000
#define BM_IN_DATA_49 0x00000000
#define BM_IN_DATA_50 0x00000000
#define BM_IN_DATA_51 0x00000000
#define BM_IN_DATA_52 0x00000000
#define BM_IN_DATA_53 0x00000000
#define BM_IN_DATA_54 0x00000000
#define BM_IN_DATA_55 0x00000000
#define BM_IN_DATA_56 0x00000000
#define BM_IN_DATA_57 0x00000000
#define BM_IN_DATA_58 0x00000000
#define BM_IN_DATA_59 0x00000000
#define BM_IN_DATA_60 0x00000000
#define BM_IN_DATA_61 0x00000000
#define BM_IN_DATA_62 0x00000000
#define BM_IN_DATA_63 0x00000000
#define BM_IN_DATA_64 0x00000000
#define BM_IN_DATA_65 0x00000000
#define BM_IN_DATA_66 0x00000000
#define BM_IN_DATA_67 0x00000000
#define BM_IN_DATA_68 0x00000000
#define BM_IN_DATA_69 0x00000000
#define BM_IN_DATA_70 0x00000000
#define BM_IN_DATA_71 0x00000000
#define BM_IN_DATA_72 0x00000000
#define BM_IN_DATA_73 0x00000000
#define BM_IN_DATA_74 0x00000000
#define BM_IN_DATA_75 0x00000000
#define BM_IN_DATA_76 0x00000000
#define BM_IN_DATA_77 0x00000000
#define BM_IN_DATA_78 0x00000000
#define BM_IN_DATA_79 0x00000000
#define BM_IN_DATA_80 0x00000000
#define BM_IN_DATA_81 0x00000000
#define BM_IN_DATA_82 0x00000000
#define BM_IN_DATA_83 0x00000000
#define BM_IN_DATA_84 0x00000000
#define BM_IN_DATA_85 0x00000000
#define BM_IN_DATA_86 0x00000000
#define BM_IN_DATA_87 0x00000000
#define BM_IN_DATA_88 0x00000000
#define BM_IN_DATA_89 0x00000000
#define BM_IN_DATA_90 0x00000000
#define BM_IN_DATA_91 0x00000000
#define BM_IN_DATA_92 0x00000000
#define BM_IN_DATA_93 0x00000000
#define BM_IN_DATA_94 0x00000000
#define BM_IN_DATA_95 0x00000000
#define BM_IN_DATA_96 0x00000000
#define BM_IN_DATA_97 0x00000000
#define BM_IN_DATA_98 0x00000000
#define BM_IN_DATA_99 0x00000000
#define BM_IN_DATA_100 0x00000000
#define BM_IN_DATA_101 0x00000000
#define BM_IN_DATA_102 0x00000000
#define BM_IN_DATA_103 0x00000000
#define BM_IN_DATA_104 0x00000000
#define BM_IN_DATA_105 0x00000000
#define BM_IN_DATA_106 0x00000000
#define BM_IN_DATA_107 0x00000000
#define BM_IN_DATA_108 0x00000000
#define BM_IN_DATA_109 0x00000000
#define BM_IN_DATA_110 0x00000000
#define BM_IN_DATA_111 0x00000000
#define BM_IN_DATA_112 0x00000000
#define BM_IN_DATA_113 0x00000000
#define BM_IN_DATA_114 0x00000000
#define BM_IN_DATA_115 0x00000000
#define BM_IN_DATA_116 0x00000000
#define BM_IN_DATA_117 0x00000000
#define BM_IN_DATA_118 0x00000000
#define BM_IN_DATA_119 0x00000000
#define BM_IN_DATA_120 0x00000000
#define BM_IN_DATA_121 0x00000000
#define BM_IN_DATA_122 0x00000000
#define BM_IN_DATA_123 0x00000000
#define BM_IN_DATA_124 0x00000000
#define BM_IN_DATA_125 0x00000000
#define BM_IN_DATA_126 0x00000000
#define BM_IN_DATA_127 0x00000000

//#define BM_OUT_DATA_0 0x00000000
#define BM_OUT_DATA_0 (XPAR_BONDMACHINEIP1_0_S00_AXI_BASEADDR + BONDMACHINEIP1_S00_AXI_SLV_REG1_OFFSET)

#define BM_OUT_DATA_1 0x00000000
#define BM_OUT_DATA_2 0x00000000
#define BM_OUT_DATA_3 0x00000000
#define BM_OUT_DATA_4 0x00000000
#define BM_OUT_DATA_5 0x00000000
#define BM_OUT_DATA_6 0x00000000
#define BM_OUT_DATA_7 0x00000000
#define BM_OUT_DATA_8 0x00000000
#define BM_OUT_DATA_9 0x00000000
#define BM_OUT_DATA_10 0x00000000
#define BM_OUT_DATA_11 0x00000000
#define BM_OUT_DATA_12 0x00000000
#define BM_OUT_DATA_13 0x00000000
#define BM_OUT_DATA_14 0x00000000
#define BM_OUT_DATA_15 0x00000000
#define BM_OUT_DATA_16 0x00000000
#define BM_OUT_DATA_17 0x00000000
#define BM_OUT_DATA_18 0x00000000
#define BM_OUT_DATA_19 0x00000000
#define BM_OUT_DATA_20 0x00000000
#define BM_OUT_DATA_21 0x00000000
#define BM_OUT_DATA_22 0x00000000
#define BM_OUT_DATA_23 0x00000000
#define BM_OUT_DATA_24 0x00000000
#define BM_OUT_DATA_25 0x00000000
#define BM_OUT_DATA_26 0x00000000
#define BM_OUT_DATA_27 0x00000000
#define BM_OUT_DATA_28 0x00000000
#define BM_OUT_DATA_29 0x00000000
#define BM_OUT_DATA_30 0x00000000
#define BM_OUT_DATA_31 0x00000000
#define BM_OUT_DATA_32 0x00000000
#define BM_OUT_DATA_33 0x00000000
#define BM_OUT_DATA_34 0x00000000
#define BM_OUT_DATA_35 0x00000000
#define BM_OUT_DATA_36 0x00000000
#define BM_OUT_DATA_37 0x00000000
#define BM_OUT_DATA_38 0x00000000
#define BM_OUT_DATA_39 0x00000000
#define BM_OUT_DATA_40 0x00000000
#define BM_OUT_DATA_41 0x00000000
#define BM_OUT_DATA_42 0x00000000
#define BM_OUT_DATA_43 0x00000000
#define BM_OUT_DATA_44 0x00000000
#define BM_OUT_DATA_45 0x00000000
#define BM_OUT_DATA_46 0x00000000
#define BM_OUT_DATA_47 0x00000000
#define BM_OUT_DATA_48 0x00000000
#define BM_OUT_DATA_49 0x00000000
#define BM_OUT_DATA_50 0x00000000
#define BM_OUT_DATA_51 0x00000000
#define BM_OUT_DATA_52 0x00000000
#define BM_OUT_DATA_53 0x00000000
#define BM_OUT_DATA_54 0x00000000
#define BM_OUT_DATA_55 0x00000000
#define BM_OUT_DATA_56 0x00000000
#define BM_OUT_DATA_57 0x00000000
#define BM_OUT_DATA_58 0x00000000
#define BM_OUT_DATA_59 0x00000000
#define BM_OUT_DATA_60 0x00000000
#define BM_OUT_DATA_61 0x00000000
#define BM_OUT_DATA_62 0x00000000
#define BM_OUT_DATA_63 0x00000000
#define BM_OUT_DATA_64 0x00000000
#define BM_OUT_DATA_65 0x00000000
#define BM_OUT_DATA_66 0x00000000
#define BM_OUT_DATA_67 0x00000000
#define BM_OUT_DATA_68 0x00000000
#define BM_OUT_DATA_69 0x00000000
#define BM_OUT_DATA_70 0x00000000
#define BM_OUT_DATA_71 0x00000000
#define BM_OUT_DATA_72 0x00000000
#define BM_OUT_DATA_73 0x00000000
#define BM_OUT_DATA_74 0x00000000
#define BM_OUT_DATA_75 0x00000000
#define BM_OUT_DATA_76 0x00000000
#define BM_OUT_DATA_77 0x00000000
#define BM_OUT_DATA_78 0x00000000
#define BM_OUT_DATA_79 0x00000000
#define BM_OUT_DATA_80 0x00000000
#define BM_OUT_DATA_81 0x00000000
#define BM_OUT_DATA_82 0x00000000
#define BM_OUT_DATA_83 0x00000000
#define BM_OUT_DATA_84 0x00000000
#define BM_OUT_DATA_85 0x00000000
#define BM_OUT_DATA_86 0x00000000
#define BM_OUT_DATA_87 0x00000000
#define BM_OUT_DATA_88 0x00000000
#define BM_OUT_DATA_89 0x00000000
#define BM_OUT_DATA_90 0x00000000
#define BM_OUT_DATA_91 0x00000000
#define BM_OUT_DATA_92 0x00000000
#define BM_OUT_DATA_93 0x00000000
#define BM_OUT_DATA_94 0x00000000
#define BM_OUT_DATA_95 0x00000000
#define BM_OUT_DATA_96 0x00000000
#define BM_OUT_DATA_97 0x00000000
#define BM_OUT_DATA_98 0x00000000
#define BM_OUT_DATA_99 0x00000000
#define BM_OUT_DATA_100 0x00000000
#define BM_OUT_DATA_101 0x00000000
#define BM_OUT_DATA_102 0x00000000
#define BM_OUT_DATA_103 0x00000000
#define BM_OUT_DATA_104 0x00000000
#define BM_OUT_DATA_105 0x00000000
#define BM_OUT_DATA_106 0x00000000
#define BM_OUT_DATA_107 0x00000000
#define BM_OUT_DATA_108 0x00000000
#define BM_OUT_DATA_109 0x00000000
#define BM_OUT_DATA_110 0x00000000
#define BM_OUT_DATA_111 0x00000000
#define BM_OUT_DATA_112 0x00000000
#define BM_OUT_DATA_113 0x00000000
#define BM_OUT_DATA_114 0x00000000
#define BM_OUT_DATA_115 0x00000000
#define BM_OUT_DATA_116 0x00000000
#define BM_OUT_DATA_117 0x00000000
#define BM_OUT_DATA_118 0x00000000
#define BM_OUT_DATA_119 0x00000000
#define BM_OUT_DATA_120 0x00000000
#define BM_OUT_DATA_121 0x00000000
#define BM_OUT_DATA_122 0x00000000
#define BM_OUT_DATA_123 0x00000000
#define BM_OUT_DATA_124 0x00000000
#define BM_OUT_DATA_125 0x00000000
#define BM_OUT_DATA_126 0x00000000
#define BM_OUT_DATA_127 0x00000000

#define BM_OUT_CTRL_0 0x00000000
#define BM_OUT_CTRL_1 0x00000000
#define BM_OUT_CTRL_2 0x00000000
#define BM_OUT_CTRL_3 0x00000000
#define BM_OUT_CTRL_4 0x00000000
#define BM_OUT_CTRL_5 0x00000000
#define BM_OUT_CTRL_6 0x00000000
#define BM_OUT_CTRL_7 0x00000000
#define BM_OUT_CTRL_8 0x00000000
#define BM_OUT_CTRL_9 0x00000000
#define BM_OUT_CTRL_10 0x00000000
#define BM_OUT_CTRL_11 0x00000000
#define BM_OUT_CTRL_12 0x00000000
#define BM_OUT_CTRL_13 0x00000000
#define BM_OUT_CTRL_14 0x00000000
#define BM_OUT_CTRL_15 0x00000000
#define BM_OUT_CTRL_16 0x00000000
#define BM_OUT_CTRL_17 0x00000000
#define BM_OUT_CTRL_18 0x00000000
#define BM_OUT_CTRL_19 0x00000000
#define BM_OUT_CTRL_20 0x00000000
#define BM_OUT_CTRL_21 0x00000000
#define BM_OUT_CTRL_22 0x00000000
#define BM_OUT_CTRL_23 0x00000000
#define BM_OUT_CTRL_24 0x00000000
#define BM_OUT_CTRL_25 0x00000000
#define BM_OUT_CTRL_26 0x00000000
#define BM_OUT_CTRL_27 0x00000000
#define BM_OUT_CTRL_28 0x00000000
#define BM_OUT_CTRL_29 0x00000000
#define BM_OUT_CTRL_30 0x00000000
#define BM_OUT_CTRL_31 0x00000000
#define BM_OUT_CTRL_32 0x00000000
#define BM_OUT_CTRL_33 0x00000000
#define BM_OUT_CTRL_34 0x00000000
#define BM_OUT_CTRL_35 0x00000000
#define BM_OUT_CTRL_36 0x00000000
#define BM_OUT_CTRL_37 0x00000000
#define BM_OUT_CTRL_38 0x00000000
#define BM_OUT_CTRL_39 0x00000000
#define BM_OUT_CTRL_40 0x00000000
#define BM_OUT_CTRL_41 0x00000000
#define BM_OUT_CTRL_42 0x00000000
#define BM_OUT_CTRL_43 0x00000000
#define BM_OUT_CTRL_44 0x00000000
#define BM_OUT_CTRL_45 0x00000000
#define BM_OUT_CTRL_46 0x00000000
#define BM_OUT_CTRL_47 0x00000000
#define BM_OUT_CTRL_48 0x00000000
#define BM_OUT_CTRL_49 0x00000000
#define BM_OUT_CTRL_50 0x00000000
#define BM_OUT_CTRL_51 0x00000000
#define BM_OUT_CTRL_52 0x00000000
#define BM_OUT_CTRL_53 0x00000000
#define BM_OUT_CTRL_54 0x00000000
#define BM_OUT_CTRL_55 0x00000000
#define BM_OUT_CTRL_56 0x00000000
#define BM_OUT_CTRL_57 0x00000000
#define BM_OUT_CTRL_58 0x00000000
#define BM_OUT_CTRL_59 0x00000000
#define BM_OUT_CTRL_60 0x00000000
#define BM_OUT_CTRL_61 0x00000000
#define BM_OUT_CTRL_62 0x00000000
#define BM_OUT_CTRL_63 0x00000000
#define BM_OUT_CTRL_64 0x00000000
#define BM_OUT_CTRL_65 0x00000000
#define BM_OUT_CTRL_66 0x00000000
#define BM_OUT_CTRL_67 0x00000000
#define BM_OUT_CTRL_68 0x00000000
#define BM_OUT_CTRL_69 0x00000000
#define BM_OUT_CTRL_70 0x00000000
#define BM_OUT_CTRL_71 0x00000000
#define BM_OUT_CTRL_72 0x00000000
#define BM_OUT_CTRL_73 0x00000000
#define BM_OUT_CTRL_74 0x00000000
#define BM_OUT_CTRL_75 0x00000000
#define BM_OUT_CTRL_76 0x00000000
#define BM_OUT_CTRL_77 0x00000000
#define BM_OUT_CTRL_78 0x00000000
#define BM_OUT_CTRL_79 0x00000000
#define BM_OUT_CTRL_80 0x00000000
#define BM_OUT_CTRL_81 0x00000000
#define BM_OUT_CTRL_82 0x00000000
#define BM_OUT_CTRL_83 0x00000000
#define BM_OUT_CTRL_84 0x00000000
#define BM_OUT_CTRL_85 0x00000000
#define BM_OUT_CTRL_86 0x00000000
#define BM_OUT_CTRL_87 0x00000000
#define BM_OUT_CTRL_88 0x00000000
#define BM_OUT_CTRL_89 0x00000000
#define BM_OUT_CTRL_90 0x00000000
#define BM_OUT_CTRL_91 0x00000000
#define BM_OUT_CTRL_92 0x00000000
#define BM_OUT_CTRL_93 0x00000000
#define BM_OUT_CTRL_94 0x00000000
#define BM_OUT_CTRL_95 0x00000000
#define BM_OUT_CTRL_96 0x00000000
#define BM_OUT_CTRL_97 0x00000000
#define BM_OUT_CTRL_98 0x00000000
#define BM_OUT_CTRL_99 0x00000000
#define BM_OUT_CTRL_100 0x00000000
#define BM_OUT_CTRL_101 0x00000000
#define BM_OUT_CTRL_102 0x00000000
#define BM_OUT_CTRL_103 0x00000000
#define BM_OUT_CTRL_104 0x00000000
#define BM_OUT_CTRL_105 0x00000000
#define BM_OUT_CTRL_106 0x00000000
#define BM_OUT_CTRL_107 0x00000000
#define BM_OUT_CTRL_108 0x00000000
#define BM_OUT_CTRL_109 0x00000000
#define BM_OUT_CTRL_110 0x00000000
#define BM_OUT_CTRL_111 0x00000000
#define BM_OUT_CTRL_112 0x00000000
#define BM_OUT_CTRL_113 0x00000000
#define BM_OUT_CTRL_114 0x00000000
#define BM_OUT_CTRL_115 0x00000000
#define BM_OUT_CTRL_116 0x00000000
#define BM_OUT_CTRL_117 0x00000000
#define BM_OUT_CTRL_118 0x00000000
#define BM_OUT_CTRL_119 0x00000000
#define BM_OUT_CTRL_120 0x00000000
#define BM_OUT_CTRL_121 0x00000000
#define BM_OUT_CTRL_122 0x00000000
#define BM_OUT_CTRL_123 0x00000000
#define BM_OUT_CTRL_124 0x00000000
#define BM_OUT_CTRL_125 0x00000000
#define BM_OUT_CTRL_126 0x00000000
#define BM_OUT_CTRL_127 0x00000000

#define BM_OUT_DATA_VALID_0 0x00000000
#define BM_OUT_DATA_VALID_1 0x00000000
#define BM_OUT_DATA_VALID_2 0x00000000
#define BM_OUT_DATA_VALID_3 0x00000000
#define BM_OUT_DATA_VALID_4 0x00000000
#define BM_OUT_DATA_VALID_5 0x00000000
#define BM_OUT_DATA_VALID_6 0x00000000
#define BM_OUT_DATA_VALID_7 0x00000000
#define BM_OUT_DATA_VALID_8 0x00000000
#define BM_OUT_DATA_VALID_9 0x00000000
#define BM_OUT_DATA_VALID_10 0x00000000
#define BM_OUT_DATA_VALID_11 0x00000000
#define BM_OUT_DATA_VALID_12 0x00000000
#define BM_OUT_DATA_VALID_13 0x00000000
#define BM_OUT_DATA_VALID_14 0x00000000
#define BM_OUT_DATA_VALID_15 0x00000000
#define BM_OUT_DATA_VALID_16 0x00000000
#define BM_OUT_DATA_VALID_17 0x00000000
#define BM_OUT_DATA_VALID_18 0x00000000
#define BM_OUT_DATA_VALID_19 0x00000000
#define BM_OUT_DATA_VALID_20 0x00000000
#define BM_OUT_DATA_VALID_21 0x00000000
#define BM_OUT_DATA_VALID_22 0x00000000
#define BM_OUT_DATA_VALID_23 0x00000000
#define BM_OUT_DATA_VALID_24 0x00000000
#define BM_OUT_DATA_VALID_25 0x00000000
#define BM_OUT_DATA_VALID_26 0x00000000
#define BM_OUT_DATA_VALID_27 0x00000000
#define BM_OUT_DATA_VALID_28 0x00000000
#define BM_OUT_DATA_VALID_29 0x00000000
#define BM_OUT_DATA_VALID_30 0x00000000
#define BM_OUT_DATA_VALID_31 0x00000000
#define BM_OUT_DATA_VALID_32 0x00000000
#define BM_OUT_DATA_VALID_33 0x00000000
#define BM_OUT_DATA_VALID_34 0x00000000
#define BM_OUT_DATA_VALID_35 0x00000000
#define BM_OUT_DATA_VALID_36 0x00000000
#define BM_OUT_DATA_VALID_37 0x00000000
#define BM_OUT_DATA_VALID_38 0x00000000
#define BM_OUT_DATA_VALID_39 0x00000000
#define BM_OUT_DATA_VALID_40 0x00000000
#define BM_OUT_DATA_VALID_41 0x00000000
#define BM_OUT_DATA_VALID_42 0x00000000
#define BM_OUT_DATA_VALID_43 0x00000000
#define BM_OUT_DATA_VALID_44 0x00000000
#define BM_OUT_DATA_VALID_45 0x00000000
#define BM_OUT_DATA_VALID_46 0x00000000
#define BM_OUT_DATA_VALID_47 0x00000000
#define BM_OUT_DATA_VALID_48 0x00000000
#define BM_OUT_DATA_VALID_49 0x00000000
#define BM_OUT_DATA_VALID_50 0x00000000
#define BM_OUT_DATA_VALID_51 0x00000000
#define BM_OUT_DATA_VALID_52 0x00000000
#define BM_OUT_DATA_VALID_53 0x00000000
#define BM_OUT_DATA_VALID_54 0x00000000
#define BM_OUT_DATA_VALID_55 0x00000000
#define BM_OUT_DATA_VALID_56 0x00000000
#define BM_OUT_DATA_VALID_57 0x00000000
#define BM_OUT_DATA_VALID_58 0x00000000
#define BM_OUT_DATA_VALID_59 0x00000000
#define BM_OUT_DATA_VALID_60 0x00000000
#define BM_OUT_DATA_VALID_61 0x00000000
#define BM_OUT_DATA_VALID_62 0x00000000
#define BM_OUT_DATA_VALID_63 0x00000000
#define BM_OUT_DATA_VALID_64 0x00000000
#define BM_OUT_DATA_VALID_65 0x00000000
#define BM_OUT_DATA_VALID_66 0x00000000
#define BM_OUT_DATA_VALID_67 0x00000000
#define BM_OUT_DATA_VALID_68 0x00000000
#define BM_OUT_DATA_VALID_69 0x00000000
#define BM_OUT_DATA_VALID_70 0x00000000
#define BM_OUT_DATA_VALID_71 0x00000000
#define BM_OUT_DATA_VALID_72 0x00000000
#define BM_OUT_DATA_VALID_73 0x00000000
#define BM_OUT_DATA_VALID_74 0x00000000
#define BM_OUT_DATA_VALID_75 0x00000000
#define BM_OUT_DATA_VALID_76 0x00000000
#define BM_OUT_DATA_VALID_77 0x00000000
#define BM_OUT_DATA_VALID_78 0x00000000
#define BM_OUT_DATA_VALID_79 0x00000000
#define BM_OUT_DATA_VALID_80 0x00000000
#define BM_OUT_DATA_VALID_81 0x00000000
#define BM_OUT_DATA_VALID_82 0x00000000
#define BM_OUT_DATA_VALID_83 0x00000000
#define BM_OUT_DATA_VALID_84 0x00000000
#define BM_OUT_DATA_VALID_85 0x00000000
#define BM_OUT_DATA_VALID_86 0x00000000
#define BM_OUT_DATA_VALID_87 0x00000000
#define BM_OUT_DATA_VALID_88 0x00000000
#define BM_OUT_DATA_VALID_89 0x00000000
#define BM_OUT_DATA_VALID_90 0x00000000
#define BM_OUT_DATA_VALID_91 0x00000000
#define BM_OUT_DATA_VALID_92 0x00000000
#define BM_OUT_DATA_VALID_93 0x00000000
#define BM_OUT_DATA_VALID_94 0x00000000
#define BM_OUT_DATA_VALID_95 0x00000000
#define BM_OUT_DATA_VALID_96 0x00000000
#define BM_OUT_DATA_VALID_97 0x00000000
#define BM_OUT_DATA_VALID_98 0x00000000
#define BM_OUT_DATA_VALID_99 0x00000000
#define BM_OUT_DATA_VALID_100 0x00000000
#define BM_OUT_DATA_VALID_101 0x00000000
#define BM_OUT_DATA_VALID_102 0x00000000
#define BM_OUT_DATA_VALID_103 0x00000000
#define BM_OUT_DATA_VALID_104 0x00000000
#define BM_OUT_DATA_VALID_105 0x00000000
#define BM_OUT_DATA_VALID_106 0x00000000
#define BM_OUT_DATA_VALID_107 0x00000000
#define BM_OUT_DATA_VALID_108 0x00000000
#define BM_OUT_DATA_VALID_109 0x00000000
#define BM_OUT_DATA_VALID_110 0x00000000
#define BM_OUT_DATA_VALID_111 0x00000000
#define BM_OUT_DATA_VALID_112 0x00000000
#define BM_OUT_DATA_VALID_113 0x00000000
#define BM_OUT_DATA_VALID_114 0x00000000
#define BM_OUT_DATA_VALID_115 0x00000000
#define BM_OUT_DATA_VALID_116 0x00000000
#define BM_OUT_DATA_VALID_117 0x00000000
#define BM_OUT_DATA_VALID_118 0x00000000
#define BM_OUT_DATA_VALID_119 0x00000000
#define BM_OUT_DATA_VALID_120 0x00000000
#define BM_OUT_DATA_VALID_121 0x00000000
#define BM_OUT_DATA_VALID_122 0x00000000
#define BM_OUT_DATA_VALID_123 0x00000000
#define BM_OUT_DATA_VALID_124 0x00000000
#define BM_OUT_DATA_VALID_125 0x00000000
#define BM_OUT_DATA_VALID_126 0x00000000
#define BM_OUT_DATA_VALID_127 0x00000000

#define BM_OUT_DATA_RECV_0 0x00000000
#define BM_OUT_DATA_RECV_1 0x00000000
#define BM_OUT_DATA_RECV_2 0x00000000
#define BM_OUT_DATA_RECV_3 0x00000000
#define BM_OUT_DATA_RECV_4 0x00000000
#define BM_OUT_DATA_RECV_5 0x00000000
#define BM_OUT_DATA_RECV_6 0x00000000
#define BM_OUT_DATA_RECV_7 0x00000000
#define BM_OUT_DATA_RECV_8 0x00000000
#define BM_OUT_DATA_RECV_9 0x00000000
#define BM_OUT_DATA_RECV_10 0x00000000
#define BM_OUT_DATA_RECV_11 0x00000000
#define BM_OUT_DATA_RECV_12 0x00000000
#define BM_OUT_DATA_RECV_13 0x00000000
#define BM_OUT_DATA_RECV_14 0x00000000
#define BM_OUT_DATA_RECV_15 0x00000000
#define BM_OUT_DATA_RECV_16 0x00000000
#define BM_OUT_DATA_RECV_17 0x00000000
#define BM_OUT_DATA_RECV_18 0x00000000
#define BM_OUT_DATA_RECV_19 0x00000000
#define BM_OUT_DATA_RECV_20 0x00000000
#define BM_OUT_DATA_RECV_21 0x00000000
#define BM_OUT_DATA_RECV_22 0x00000000
#define BM_OUT_DATA_RECV_23 0x00000000
#define BM_OUT_DATA_RECV_24 0x00000000
#define BM_OUT_DATA_RECV_25 0x00000000
#define BM_OUT_DATA_RECV_26 0x00000000
#define BM_OUT_DATA_RECV_27 0x00000000
#define BM_OUT_DATA_RECV_28 0x00000000
#define BM_OUT_DATA_RECV_29 0x00000000
#define BM_OUT_DATA_RECV_30 0x00000000
#define BM_OUT_DATA_RECV_31 0x00000000
#define BM_OUT_DATA_RECV_32 0x00000000
#define BM_OUT_DATA_RECV_33 0x00000000
#define BM_OUT_DATA_RECV_34 0x00000000
#define BM_OUT_DATA_RECV_35 0x00000000
#define BM_OUT_DATA_RECV_36 0x00000000
#define BM_OUT_DATA_RECV_37 0x00000000
#define BM_OUT_DATA_RECV_38 0x00000000
#define BM_OUT_DATA_RECV_39 0x00000000
#define BM_OUT_DATA_RECV_40 0x00000000
#define BM_OUT_DATA_RECV_41 0x00000000
#define BM_OUT_DATA_RECV_42 0x00000000
#define BM_OUT_DATA_RECV_43 0x00000000
#define BM_OUT_DATA_RECV_44 0x00000000
#define BM_OUT_DATA_RECV_45 0x00000000
#define BM_OUT_DATA_RECV_46 0x00000000
#define BM_OUT_DATA_RECV_47 0x00000000
#define BM_OUT_DATA_RECV_48 0x00000000
#define BM_OUT_DATA_RECV_49 0x00000000
#define BM_OUT_DATA_RECV_50 0x00000000
#define BM_OUT_DATA_RECV_51 0x00000000
#define BM_OUT_DATA_RECV_52 0x00000000
#define BM_OUT_DATA_RECV_53 0x00000000
#define BM_OUT_DATA_RECV_54 0x00000000
#define BM_OUT_DATA_RECV_55 0x00000000
#define BM_OUT_DATA_RECV_56 0x00000000
#define BM_OUT_DATA_RECV_57 0x00000000
#define BM_OUT_DATA_RECV_58 0x00000000
#define BM_OUT_DATA_RECV_59 0x00000000
#define BM_OUT_DATA_RECV_60 0x00000000
#define BM_OUT_DATA_RECV_61 0x00000000
#define BM_OUT_DATA_RECV_62 0x00000000
#define BM_OUT_DATA_RECV_63 0x00000000
#define BM_OUT_DATA_RECV_64 0x00000000
#define BM_OUT_DATA_RECV_65 0x00000000
#define BM_OUT_DATA_RECV_66 0x00000000
#define BM_OUT_DATA_RECV_67 0x00000000
#define BM_OUT_DATA_RECV_68 0x00000000
#define BM_OUT_DATA_RECV_69 0x00000000
#define BM_OUT_DATA_RECV_70 0x00000000
#define BM_OUT_DATA_RECV_71 0x00000000
#define BM_OUT_DATA_RECV_72 0x00000000
#define BM_OUT_DATA_RECV_73 0x00000000
#define BM_OUT_DATA_RECV_74 0x00000000
#define BM_OUT_DATA_RECV_75 0x00000000
#define BM_OUT_DATA_RECV_76 0x00000000
#define BM_OUT_DATA_RECV_77 0x00000000
#define BM_OUT_DATA_RECV_78 0x00000000
#define BM_OUT_DATA_RECV_79 0x00000000
#define BM_OUT_DATA_RECV_80 0x00000000
#define BM_OUT_DATA_RECV_81 0x00000000
#define BM_OUT_DATA_RECV_82 0x00000000
#define BM_OUT_DATA_RECV_83 0x00000000
#define BM_OUT_DATA_RECV_84 0x00000000
#define BM_OUT_DATA_RECV_85 0x00000000
#define BM_OUT_DATA_RECV_86 0x00000000
#define BM_OUT_DATA_RECV_87 0x00000000
#define BM_OUT_DATA_RECV_88 0x00000000
#define BM_OUT_DATA_RECV_89 0x00000000
#define BM_OUT_DATA_RECV_90 0x00000000
#define BM_OUT_DATA_RECV_91 0x00000000
#define BM_OUT_DATA_RECV_92 0x00000000
#define BM_OUT_DATA_RECV_93 0x00000000
#define BM_OUT_DATA_RECV_94 0x00000000
#define BM_OUT_DATA_RECV_95 0x00000000
#define BM_OUT_DATA_RECV_96 0x00000000
#define BM_OUT_DATA_RECV_97 0x00000000
#define BM_OUT_DATA_RECV_98 0x00000000
#define BM_OUT_DATA_RECV_99 0x00000000
#define BM_OUT_DATA_RECV_100 0x00000000
#define BM_OUT_DATA_RECV_101 0x00000000
#define BM_OUT_DATA_RECV_102 0x00000000
#define BM_OUT_DATA_RECV_103 0x00000000
#define BM_OUT_DATA_RECV_104 0x00000000
#define BM_OUT_DATA_RECV_105 0x00000000
#define BM_OUT_DATA_RECV_106 0x00000000
#define BM_OUT_DATA_RECV_107 0x00000000
#define BM_OUT_DATA_RECV_108 0x00000000
#define BM_OUT_DATA_RECV_109 0x00000000
#define BM_OUT_DATA_RECV_110 0x00000000
#define BM_OUT_DATA_RECV_111 0x00000000
#define BM_OUT_DATA_RECV_112 0x00000000
#define BM_OUT_DATA_RECV_113 0x00000000
#define BM_OUT_DATA_RECV_114 0x00000000
#define BM_OUT_DATA_RECV_115 0x00000000
#define BM_OUT_DATA_RECV_116 0x00000000
#define BM_OUT_DATA_RECV_117 0x00000000
#define BM_OUT_DATA_RECV_118 0x00000000
#define BM_OUT_DATA_RECV_119 0x00000000
#define BM_OUT_DATA_RECV_120 0x00000000
#define BM_OUT_DATA_RECV_121 0x00000000
#define BM_OUT_DATA_RECV_122 0x00000000
#define BM_OUT_DATA_RECV_123 0x00000000
#define BM_OUT_DATA_RECV_124 0x00000000
#define BM_OUT_DATA_RECV_125 0x00000000
#define BM_OUT_DATA_RECV_126 0x00000000
#define BM_OUT_DATA_RECV_127 0x00000000


