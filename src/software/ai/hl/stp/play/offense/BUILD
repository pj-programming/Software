package(default_visibility = ["//visibility:public"])

# We force linking for all plays so that the static variables required for the
# "factory" design pattern to work are linked in
# https://www.bfilipek.com/2018/02/static-vars-static-lib.html

cc_library(
    name = "offense_play",
    srcs = [
        "offense_play.cpp",
    ],
    hdrs = [
        "offense_play.h",
    ],
    deps = [
        "//shared:constants",
        "//shared/parameter:cpp_configs",
        "//software/ai/hl/stp/play",
        "//software/ai/hl/stp/play/crease_defense:crease_defense_play",
        "//software/ai/hl/stp/play/shoot_or_pass:shoot_or_pass_play",
        "//software/ai/hl/stp/tactic/crease_defender:crease_defender_tactic",
        "//software/ai/hl/stp/tactic/shadow_enemy:shadow_enemy_tactic",
        "//software/logger",
        "//software/util/generic_factory",
        "@sml",
    ],
    alwayslink = True,
)

cc_test(
    name = "offense_play_test",
    srcs = ["offense_play_test.cpp"],
    deps = [
        ":offense_play",
        "//shared/test_util:tbots_gtest_main",
        "//software/simulated_tests:simulated_er_force_sim_play_test_fixture",
        "//software/simulated_tests/validation:validation_function",
        "//software/test_util",
        "//software/time:duration",
        "//software/world",
    ],
)
