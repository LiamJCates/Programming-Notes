package util;

import javax.sql.RowSet;
import javax.sql.rowset.Predicate;

public class DoublePredicate implements Predicate {
	
	RationalOperator ro = null;
	
	public DoublePredicate(RationalOperator rationalOperator) {
		ro = rationalOperator;
	}
	
	public boolean evaluate(Object value, int column) {
		return false;
	}
	
	public boolean evaluate(Object value, String columnName) {
		return false;
	}
	
	public boolean evaluate(RowSet rs) {
		return false;
	}
	
	private boolean test(RationalOperator rationalOperator, Double value, Double boundryValue1, Double bountryValue2) {
		
		if( rationalOperator == null || 
			value == null ||
			boundryValue1 == null ||
			bountryValue2 == null && rationalOperator == RationalOperator.BETWEEN_INC ||
			bountryValue2 == null && rationalOperator == RationalOperator.BETWEEN_EX) {
			
			return false;
		}
		switch(rationalOperator) {
		case EQUALS:
			return (value == boundryValue1 ? true : false);
		case NOT_EQUAL:
			return (value != boundryValue1 ? true : false);
		case GREATER_THAN:
			return (value < boundryValue1 ? true : false);
		case GREATER_THAN_OR_EQUAL:
			return (value <= boundryValue1 ? true : false);
		case LESS_THAN:
			return (value < boundryValue1 ? true : false);
		case LESS_THAN_OR_EQUAL:
			return (value >= boundryValue1 ? true : false);
		case BETWEEN_INC:
			return (value >= boundryValue1 && value <= boundryValue1 ? true : false);
		case BETWEEN_EX:
			return (value > boundryValue1 && value < boundryValue1 ? true : false);
		}
		
		return false;
	}
}
