#include <iostream>
#include "gtest/gtest.h"
#include "ChessFigure.h"
/*TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}*/
//-----------------------------------------------------------------------------------------------------
/*TEST(LAB2, PawnShouldBeCorrectMove0)
{
	ChessFigure* figure = new ChessFigure(ChessFigure::PAWN, "E2");
	EXPECT_TRUE(figure->Move("E3"));
}

TEST(LAB2, PawnShouldBeCorrectMove1)
{
	ChessFigure *figure = new ChessFigure(ChessFigure::PAWN, "E2");
	EXPECT_TRUE(figure->Move("E4"));
}

TEST(LAB2, PawnShouldBeCorrectMove2)
{
	ChessFigure *figure = new ChessFigure(ChessFigure::PAWN, "E4");
	EXPECT_TRUE(figure->Move("E5"));
}

TEST(LAB2, PawnShouldBeIncorrectMove)
{
	ChessFigure *figure = new ChessFigure(ChessFigure::PAWN, "E2");
	EXPECT_FALSE(figure->Move("C5"));
}*/
TEST(PawnTest, PawnMovesOneFieldCorrect){
    //for one field forward("with same letter")
    ChessFigure *figure = new ChessFigure(ChessFigure::PAWN, "B3");
    EXPECT_TRUE(figure->Move("B4"));
}

TEST(PawnTest, PawnMovesOneFieldIncorrect){
    //for one field forward("with same letter")
    ChessFigure *figure = new ChessFigure(ChessFigure::PAWN, "H3");
    EXPECT_FALSE(figure->Move("G4"));
}

TEST(PawnTest, PawnMovesTwoFieldsCorrect){
    //for two fields forward, only if didn't move before(if 2nd coordinate is '2')
    ChessFigure *figure = new ChessFigure(ChessFigure::PAWN, "B3");
    EXPECT_TRUE(figure->Move("B5"));
}

TEST(PawnTest, PawnMovesTwoFieldsIncorrect){
    //for two fields forward, only if didn't move before(if 2nd coordinate is '2')
    ChessFigure *figure = new ChessFigure(ChessFigure::PAWN, "H3");
    EXPECT_FALSE(figure->Move("G5"));
}
//-----------------------------------------------------------------------------------------------------
/*TEST(LAB2, RookShouldBeCorrectMove)
{
	ChessFigure *figure = new ChessFigure(ChessFigure::ROOK,"E2");
	EXPECT_TRUE(figure->Move("C2"));
}

TEST(LAB2, RookShouldBeIncorrectMove)
{
	ChessFigure *figure = new ChessFigure(ChessFigure::ROOK, "E2");
	EXPECT_FALSE(figure->Move("C5"));
}*/
TEST(RookTest, RookMovesVerticalCorrect){
    //moving on fields with same letter coordinate
    ChessFigure *figure = new ChessFigure(ChessFigure::ROOK, "A1");
    EXPECT_TRUE(figure->Move("A8"));
}
TEST(RookTest, RookMovesHorizontalCorrect){
    //moving on fields with same number coordinate
    ChessFigure *figure = new ChessFigure(ChessFigure::ROOK, "A1");
    EXPECT_TRUE(figure->Move("H1"));
}

TEST(RookTest, RookMovesIncorrect){
    //moving on other fields
    ChessFigure *figure = new ChessFigure(ChessFigure::ROOK, "A1");
    EXPECT_FALSE(figure->Move("G5"));
}
TEST(RookTest, RookMovesIncorrectSameField){
    //moving on other fields
    ChessFigure *figure = new ChessFigure(ChessFigure::ROOK, "A1");
    EXPECT_FALSE(figure->Move("A1"));
}
//-----------------------------------------------------------------------------------------------------
/*TEST(LAB2, KnightShouldBeCorrectMove)
{
	ChessFigure *figure = new ChessFigure(ChessFigure::KNIGHT, "B1");
	EXPECT_TRUE(figure->Move("C3"));
}
TEST(LAB2, KnightShouldBeIncorrectMove)
{
	ChessFigure *figure = new ChessFigure(ChessFigure::KNIGHT, "B1");
	EXPECT_FALSE(figure->Move("C5"));
}*/
TEST(KnightTest, KnightMovesVerticalCorrect){
    //moving like letter 'L', vertical oriented
    ChessFigure *figure = new ChessFigure(ChessFigure::KNIGHT, "B1");
    EXPECT_TRUE(figure->Move("A3"));
}
TEST(KnightTest, KnightMovesHorizontalCorrect){
    //moving like letter 'L', horizontal oriented
    ChessFigure *figure = new ChessFigure(ChessFigure::KNIGHT, "B1");
    EXPECT_TRUE(figure->Move("D2"));
}
TEST(KnightTest, KnightMovesIncorrect){
    //moving like letter 'L', horizontal oriented
    ChessFigure *figure = new ChessFigure(ChessFigure::KNIGHT, "B1");
    EXPECT_FALSE(figure->Move("C2"));
}
//-----------------------------------------------------------------------------------------------------
/*TEST(LAB2, BishopShouldBeCorrectMove)
{
	ChessFigure *figure = new ChessFigure(ChessFigure::BISHOP, "C1");
	EXPECT_TRUE(figure->Move("E3"));
}

TEST(LAB2, BishopShouldBeIncorrectMove)
{
	ChessFigure *figure = new ChessFigure(ChessFigure::BISHOP, "C1");
	EXPECT_FALSE(figure->Move("C3"));
}*/
TEST(BishopTest, BishopMovesMainDiagCorrect){
    //moving on main diagonal(from A to H and from 1 to 8, by adding letter-number pair simultaneously)
    ChessFigure *figure = new ChessFigure(ChessFigure::BISHOP, "D4");
    EXPECT_TRUE(figure->Move("G7"));
}
TEST(BishopTest, BishopMovesSecondDiagCorrect){
    //moving on main diagonal(from A to H and from 8 to 1, by adding letter-number pair simultaneously)
    ChessFigure *figure = new ChessFigure(ChessFigure::BISHOP, "D4");
    EXPECT_TRUE(figure->Move("C6"));
}
TEST(BishopTest, BishopMovesIncorrect){
    //every other case which is not on diagonal from starting field
    ChessFigure *figure = new ChessFigure(ChessFigure::BISHOP, "D4");
    EXPECT_FALSE(figure->Move("C6"));
}
TEST(BishopTest, BishopMovesIncorrectSameField){
    //every other case which is not on diagonal from starting field
    ChessFigure *figure = new ChessFigure(ChessFigure::BISHOP, "D4");
    EXPECT_FALSE(figure->Move("D4"));
}
//-----------------------------------------------------------------------------------------------------
/*TEST(LAB2, KingShouldBeCorrectMove)
{
	ChessFigure* figure = new ChessFigure(ChessFigure::KING, "E1");
	EXPECT_TRUE(figure->Move("E2"));
}
TEST(LAB2, KingShouldBeIncorrectMove)
{
	ChessFigure* figure = new ChessFigure(ChessFigure::KING, "E1");
	EXPECT_FALSE(figure->Move("E8"));
}*/

TEST(KingTest, KingMovesVerticalCorrect){
    ChessFigure* figure = new ChessFigure(ChessFigure::KING, "E3");
    EXPECT_TRUE(figure->Move("E4"));
}
TEST(KingTest, KingMovesHorizontalCorrect){
    ChessFigure* figure = new ChessFigure(ChessFigure::KING, "E3");
    EXPECT_TRUE(figure->Move("D3"));
}
TEST(KingTest, KingMovesMainDiagCorrect){
    ChessFigure* figure = new ChessFigure(ChessFigure::KING, "E3");
    EXPECT_TRUE(figure->Move("F4"));
}
TEST(KingTest, KingMovesSecondDiagCorrect){
    ChessFigure* figure = new ChessFigure(ChessFigure::KING, "E3");
    EXPECT_TRUE(figure->Move("F2"));
}
TEST(KingTest, KingMovesVerticalIncorrect){
    ChessFigure* figure = new ChessFigure(ChessFigure::KING, "E3");
    EXPECT_FALSE(figure->Move("E1"));
}
TEST(KingTest, KingMovesHorizontalIncorrect){
    ChessFigure* figure = new ChessFigure(ChessFigure::KING, "E3");
    EXPECT_FALSE(figure->Move("A3"));
}
TEST(KingTest, KingMovesMainDiagIncorrect){
    ChessFigure* figure = new ChessFigure(ChessFigure::KING, "E3");
    EXPECT_FALSE(figure->Move("H6"));
}
TEST(KingTest, KingMovesSecondDiagIncorrect){
    ChessFigure* figure = new ChessFigure(ChessFigure::KING, "E3");
    EXPECT_FALSE(figure->Move("A7"));
}
TEST(KingTest, KingMovesIncorrectSameField){
    ChessFigure* figure = new ChessFigure(ChessFigure::KING, "E3");
    EXPECT_FALSE(figure->Move("E3"));
}
//-----------------------------------------------------------------------------------------------------
/*TEST(LAB2, QueenShouldBeCorrectMoveVertical)
{
	ChessFigure* figure = new ChessFigure(ChessFigure::QUEEN, "D1");
	EXPECT_TRUE(figure->Move("D8"));
}

TEST(LAB2, QueenShouldBeCorrectMoveDiagonal)
{
	ChessFigure* figure = new ChessFigure(ChessFigure::QUEEN, "D1");
	EXPECT_TRUE(figure->Move("H5"));
}

TEST(LAB2, QueenShouldBeIncorrectMove)
{
	ChessFigure* figure = new ChessFigure(ChessFigure::QUEEN, "D1");
	EXPECT_FALSE(figure->Move("E3"));
}*/
TEST(QueenTest, QueenMovesVerticalCorrect){
    ChessFigure* figure = new ChessFigure(ChessFigure::QUEEN, "E3");
    EXPECT_TRUE(figure->Move("E8"));
}
TEST(QueenTest, QueenMovesHorizontalCorrect){
    ChessFigure* figure = new ChessFigure(ChessFigure::QUEEN, "E3");
    EXPECT_TRUE(figure->Move("A3"));
}
TEST(QueenTest, QueenMovesMainDiagCorrect){
    ChessFigure* figure = new ChessFigure(ChessFigure::QUEEN, "E3");
    EXPECT_TRUE(figure->Move("C1"));
}
TEST(QueenTest, QueenMovesSecondDiagCorrect){
    ChessFigure* figure = new ChessFigure(ChessFigure::QUEEN, "E3");
    EXPECT_TRUE(figure->Move("A7"));
}
TEST(QueenTest, QueenMovesIncorrect){
    ChessFigure* figure = new ChessFigure(ChessFigure::QUEEN, "E3");
    EXPECT_FALSE(figure->Move("B2"));
}
TEST(QueenTest, QueenMovesIncorrectSameField){
    ChessFigure* figure = new ChessFigure(ChessFigure::QUEEN, "E3");
    EXPECT_FALSE(figure->Move("E3"));
}

//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------








