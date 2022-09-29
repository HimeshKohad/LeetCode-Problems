public class MyCalendar {
    List<int[]> booking;

    MyCalendar() {
        booking = new ArrayList();
    }

    public boolean book(int start, int end) {
        for (int[] temp: booking) {
            if (temp[0] < end && start < temp[1]) {
                return false;
            }
        }
        booking.add(new int[]{start, end});
        return true;
    }
}
