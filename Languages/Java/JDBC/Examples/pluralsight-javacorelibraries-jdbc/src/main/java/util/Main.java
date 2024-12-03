package util;

public class Main {

	public static void main(String[] args) throws Exception {
		int orderNumber = 10420;
		String newStatus = "Tested";
		
		try {
			OrderComponent comp = new OrderComponent();
			if(comp.updateOrdersStatus(orderNumber, newStatus)) {
				System.out.println("Order #" + orderNumber + " updated status to " + newStatus);
			}else {
				System.out.println("Order #" + orderNumber + " was NOT updated");	
			}
		} catch (Exception exception) {
			util.ExceptionHandler.handleException(exception);
		}
	}
}
