package(default_visibility = ["//visibility:public"])

cc_library(
    name = "pass",
    srcs = ["pass.cpp"],
    hdrs = ["pass.h"],
    deps = [
        "//software/ai/evaluation:calc_best_shot",
        "//software/world:robot",
    ],
)

cc_test(
    name = "pass_test",
    srcs = ["pass_test.cpp"],
    deps = [
        ":pass",
        "//shared/test_util:tbots_gtest_main",
        "//software/test_util",
    ],
)

cc_library(
    name = "calc_best_shot",
    srcs = [
        "calc_best_shot.cpp",
    ],
    hdrs = [
        "calc_best_shot.h",
    ],
    deps = [
        ":shot",
        "//shared:constants",
        "//software/geom:angle_map",
        "//software/geom:angle_segment",
        "//software/geom:segment",
        "//software/geom/algorithms",
        "//software/world",
    ],
)

cc_test(
    name = "calc_best_shot_test",
    srcs = [
        "calc_best_shot_test.cpp",
    ],
    deps = [
        ":calc_best_shot",
        ":shot",
        "//shared:constants",
        "//shared/test_util:tbots_gtest_main",
        "//software/test_util",
    ],
)

cc_library(
    name = "deflect_off_enemy_target",
    srcs = ["deflect_off_enemy_target.cpp"],
    hdrs = ["deflect_off_enemy_target.h"],
    deps = [
        ":shot",
        "//shared:constants",
        "//software/geom:triangle",
        "//software/geom/algorithms",
        "//software/world",
    ],
)

cc_test(
    name = "deflect_off_enemy_target_test",
    srcs = ["deflect_off_enemy_target_test.cpp"],
    deps = [
        ":deflect_off_enemy_target",
        ":shot",
        "//shared/test_util:tbots_gtest_main",
        "//software/test_util",
    ],
)

cc_library(
    name = "detect_threat",
    srcs = ["detect_threat.cpp"],
    hdrs = ["detect_threat.h"],
    deps = [
        "//shared:constants",
        "//software/geom/algorithms",
        "//software/world:ball",
        "//software/world:field",
    ],
)

cc_test(
    name = "detect_threat_test",
    srcs = ["detect_threat_test.cpp"],
    deps = [
        ":detect_threat",
        ":shot",
        "//shared/test_util:tbots_gtest_main",
        "//software/test_util",
        "//software/time:timestamp",
        "//software/world:ball",
    ],
)

cc_library(
    name = "enemy_threat",
    srcs = ["enemy_threat.cpp"],
    hdrs = ["enemy_threat.h"],
    deps = [
        ":calc_best_shot",
        ":intercept",
        ":possession",
        ":shot",
        "//shared:constants",
        "//software/geom/algorithms",
        "//software/world",
        "//software/world:team",
    ],
)

cc_test(
    name = "enemy_threat_test",
    srcs = ["enemy_threat_test.cpp"],
    deps = [
        ":enemy_threat",
        "//shared/test_util:tbots_gtest_main",
        "//software/test_util",
        "//software/world:ball",
    ],
)

cc_library(
    name = "find_open_areas",
    srcs = ["find_open_areas.cpp"],
    hdrs = ["find_open_areas.h"],
    deps = [
        ":shot",
        "//shared/parameter:cpp_configs",
        "//software/geom/algorithms",
        "//software/world",
    ],
)

cc_library(
    name = "intercept",
    srcs = ["intercept.cpp"],
    hdrs = ["intercept.h"],
    deps = [
        ":shot",
        "//shared:constants",
        "//software/ai/evaluation:pass",
        "//software/geom/algorithms",
        "//software/optimization:gradient_descent",
        "//software/world:ball",
        "//software/world:field",
        "//software/world:robot",
    ],
)

cc_test(
    name = "intercept_test",
    srcs = ["intercept_test.cpp"],
    deps = [
        ":intercept",
        "//shared/test_util:tbots_gtest_main",
        "//software/test_util",
    ],
)

cc_library(
    name = "possession",
    srcs = ["possession.cpp"],
    hdrs = ["possession.h"],
    deps = [
        ":intercept",
        ":shot",
        "//software/world:ball",
        "//software/world:field",
        "//software/world:robot",
        "//software/world:team",
    ],
)

cc_test(
    name = "possession_test",
    srcs = ["possession_test.cpp"],
    deps = [
        ":possession",
        "//shared:constants",
        "//shared/test_util:tbots_gtest_main",
        "//software/test_util",
    ],
)

cc_library(
    name = "shot",
    srcs = ["shot.cpp"],
    hdrs = ["shot.h"],
    deps = ["//software/geom:point"],
)

cc_library(
    name = "keep_away",
    srcs = ["keep_away.cpp"],
    hdrs = ["keep_away.h"],
    deps = [
        "//shared/parameter:cpp_configs",
        "//software/ai/passing:cost_functions",
        "//software/geom/algorithms",
        "//software/optimization:gradient_descent",
        "//software/world",
        "//software/world:ball",
        "//software/world:field",
        "//software/world:robot",
    ],
)

cc_test(
    name = "keep_away_test",
    srcs = ["keep_away_test.cpp"],
    deps = [
        ":keep_away",
        "//shared:constants",
        "//shared/test_util:tbots_gtest_main",
        "//software/test_util",
        "//software/world",
    ],
)
