#ifndef COMPUTERVIEW_H
#define COMPUTERVIEW_H

#include <Wt/WContainerWidget>
#include <Wt/WString>
#include <boost/signals2.hpp>

class ComputerView : public Wt::WContainerWidget
{
private:
	Wt::WApplication *app;
	Wt::WString _computerName;
	bool _ledStatus;
	bool _powerStatus;

	Wt::WPushButton *_btn_pw_switch_press;
	Wt::WPushButton *_btn_pw_switch_force_off;

	Wt::WImage *_img_led;
	Wt::WText *_ping_txt;
	Wt::WTextArea *_logs_edit;

	std::shared_ptr<Wt::WFileResource> _ico_led_on_file;
	std::shared_ptr<Wt::WFileResource> _ico_led_off_file;
	std::shared_ptr<Wt::WFileResource> _ico_ping_file;
	std::shared_ptr<Wt::WFileResource> _ico_pwr_switch_file;

	void btn_pw_switch_press_clicked();
	void btn_pw_switch_force_off_clicked();

	Wt::WFileResource *getImg(const Wt::WString &name);
	void setPowerLedStatus(bool status);
public:
	ComputerView(Wt::WApplication *app,
		     const Wt::WString &computerName,
		     bool writeAccess,
		     Wt::WContainerWidget *parent = NULL);

	Wt::WString computerName() const { return _computerName; };

	/* slots */
	void powerLedStatusChanged(bool status);
	void consoleDataAdded(const Wt::WString &data);
	void setPingDelay(double delay);

	/* signals */
	boost::signals2::signal<void ()> sig_pwSwitchPress;
	boost::signals2::signal<void ()> sig_pwSwitchForceOff;
};

#endif // COMPUTERVIEW_H
