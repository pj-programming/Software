#include "software/ai/hl/stp/play/shoot_or_pass/shoot_or_pass_play.h"

#include <gtest/gtest.h>

#include "software/simulated_tests/simulated_play_test_fixture.h"
#include "software/simulated_tests/terminating_validation_functions/friendly_scored_validation.h"
#include "software/simulated_tests/validation/validation_function.h"
#include "software/test_util/test_util.h"
#include "software/time/duration.h"
#include "software/world/world.h"

class ShootOrPassPlayTest : public SimulatedPlayTestFixture
{
   protected:
    Field field = Field::createSSLDivisionBField();
};

TEST_F(ShootOrPassPlayTest, test_shoot_or_pass_play)
{
    BallState ball_state(Point(-4.4, 2.9), Vector(0, 0));
    auto friendly_robots = TestUtil::createStationaryRobotStatesWithId({
        field.friendlyGoalCenter(),
        Point(-4.5, 3.0),
        Point(-2, 1.5),
        Point(-2, 0.5),
        Point(-2, -1.7),
        Point(-2, -1.5),
    });
    setFriendlyGoalie(0);
    auto enemy_robots = TestUtil::createStationaryRobotStatesWithId(
        {Point(1, 0), Point(1, 2.5), Point(1, -2.5), field.enemyGoalCenter(),
         field.enemyDefenseArea().negXNegYCorner(),
         field.enemyDefenseArea().negXPosYCorner()});
    setEnemyGoalie(0);
    setAIPlay(TYPENAME(ShootOrPassPlay));
    setRefereeCommand(RefereeCommand::FORCE_START, RefereeCommand::STOP);

    std::vector<ValidationFunction> terminating_validation_functions = {friendlyScored};

    std::vector<ValidationFunction> non_terminating_validation_functions = {};

    runTest(field, ball_state, friendly_robots, enemy_robots,
            terminating_validation_functions, non_terminating_validation_functions,
            Duration::fromSeconds(15));
}
